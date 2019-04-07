package com.magee.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.magee.dao.UserData;
import com.magee.pojo.Student;
import com.magee.pojo.User;
import com.magee.until.JdbcUtil;

public class UserDataImpl implements UserData{

	@Override
	public boolean modifyInfo(User stu) {
		if(deleteFromId(stu.getId()) && add(stu)) {
			return true;
		}
		return false;
	}

	@Override
	public User checkInfo(String id, String pwd) {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from user where id = ? and pwd = ?");
			ps.setString(1, id);
			ps.setString(2, pwd);
			rs = ps.executeQuery();
		User temp = null;
			while(rs.next()) {
				temp = new User();
				temp.setId(rs.getString(1));
				temp.setUname(rs.getString(2));
				temp.setPwd(rs.getString(3));
			}
			return temp;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}
	
	public boolean deleteFromId(String id) {
		//判断是否存在该id
			if(IsIdexist(id) == null) return false;
		
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		
		try {
			ps = conn.prepareStatement("delete from user where id = ?");
			ps.setString(1,id);
			ps.execute();
			return true;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}finally {
			JdbcUtil.close(ps, conn);
		}

	}
	
	public User IsIdexist(String id) {	
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from user where id = ?");
			ps.setString(1, id);
			rs = ps.executeQuery();
			User temp = null;
			while(rs.next()) {
				temp = new User();
				temp.setId(rs.getString(1));
				temp.setUname(rs.getString(2));
				temp.setPwd(rs.getString(3));
			}
			return temp;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}
	public boolean add(User user) {
		//检查是否有id重复
			if(IsIdexist(user.getId()) != null) return false;
		
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement("insert into user (id,uname,pwd) value (?,?,?)");
			
			ps.setString(1, user.getId());
			ps.setString(2, user.getUname());
			ps.setString(3, user.getPwd());
			ps.execute();
			return true;				
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}finally {
			JdbcUtil.close(ps,conn);
		}
		
	}
	

}
