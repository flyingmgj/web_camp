package com.magee.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;
import java.util.List;
import com.magee.dao.StuData;
import com.magee.pojo.Student;
import com.magee.until.JdbcUtil;

public class StuDataImpl implements StuData{

	@Override
	public boolean add(Student stu) {
		//检查是否有id重复
			if(IsIdexist(stu.getId()) != null) return false;
		
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement("insert into student (id,name,pwd,grade,ph_number,direction,introduce,img ) value (?,?,?,?,?,?,?,?)");
			
			ps.setString(1, stu.getId());
			ps.setString(2, stu.getName());
			ps.setString(3, stu.getPwd());
			ps.setString(4, stu.getGrade());
			ps.setString(5, stu.getPh_number());
			ps.setString(6, stu.getDirection());
		//get inputStream from web ----but i didn`t learn it yet;
		//so i use a constant io to replace it	
			ps.setString(7,stu.getIntroduce());
			ps.setString(8,stu.getImg());
			ps.execute();
			return true;				
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}finally {
			JdbcUtil.close(ps,conn);
		}
		
	}

	@Override
	public boolean deleteFromId(String id) {
		//判断是否存在该id
			if(IsIdexist(id) == null) return false;
		
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		
		try {
			ps = conn.prepareStatement("delete from student where id = ?");
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

	@Override
	public boolean deleteFromName(String name) {
		//判断id是否存在	
			if(IsIdexist(name) == null) return false;
		
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		
		try {
			ps = conn.prepareStatement("delete from student where name = ?");
			ps.setString(1,name);
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

	@Override
	public Student checkInfo(String id, String pwd) {
		
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student where id = ? and pwd = ?");
			ps.setString(1, id);
			ps.setString(2, pwd);
			rs = ps.executeQuery();
			Student temp = null;
			while(rs.next()) {
				temp = new Student();
				RsToStu(temp, rs);
			}
			return temp;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public Student IsIdexist(String id) {	
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student where id = ?");
			ps.setString(1, id);
			rs = ps.executeQuery();
			Student temp = null;
			while(rs.next()) {
				temp = new Student();
				RsToStu(temp, rs);
			}
			return temp;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public Student IsNameexist(String name) {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student where name = ?");
			ps.setString(1, name);
			rs = ps.executeQuery();
			Student temp = null;
			while(rs.next()) {
				temp = new Student();
				RsToStu(temp, rs);
			}
			return temp;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public List<Student> getAllInfo() {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student ");
			rs = ps.executeQuery();
			Student temp = null;
			List<Student> list = new LinkedList<Student>();
			while(rs.next()) {
				temp = new Student();
				RsToStu(temp, rs);
				list.add(temp);
			}
			return list;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public List<String> getAllgrade() {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student ");
			rs = ps.executeQuery();
			String temp = null;
			List<String> list = new LinkedList<String>();
			while(rs.next()) {
				temp = new String();
				temp = rs.getString(4);
				list.add(temp);
			}
			return list;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public List<Student> getgrade(String grade) {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student where grade = ?");
			ps.setString(1, grade);
			rs = ps.executeQuery();
			Student temp = null;
			List<Student> list = new LinkedList<Student>();
			while(rs.next()) {
				temp = new Student();
				RsToStu(temp,rs);
				list.add(temp);
			}
			return list;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public List<String> getAllGroup() {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student");
			String temp = null;
			rs = ps.executeQuery();
			
			List<String> list = new LinkedList<String>();
			
			while(rs.next()) {
				
				temp = new String();
				temp = rs.getString(6);
				list.add(temp);
			}
			return list;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public List<Student> getGroup(String direction) {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student where direction = ?");
			ps.setString(1, direction);
			rs = ps.executeQuery();
			Student temp = null;
			List<Student> list = new LinkedList<Student>();
			while(rs.next()) {
				temp = new Student();
				RsToStu(temp,rs);
				list.add(temp);
			}
			return list;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public List<String> getAllId() {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student");
			String temp = null;
			List<String> list = new LinkedList<String>();
			while(rs.next()) {
				temp = new String();
				temp = rs.getString(1);
				list.add(temp);
			}
			return list;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public Student getId(String id) {
		Connection conn = JdbcUtil.getMysqlConn();
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement("select * from student where id = ?");
			ps.setString(1, id);
			rs = ps.executeQuery();
			Student temp = null;
			while(rs.next()) {
				temp = new Student();
				RsToStu(temp,rs);
			}
			return temp;
				
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}finally {
			JdbcUtil.close(rs, ps,conn);
		}
	}

	@Override
	public void modifyInfo(Student stu) {

			deleteFromId(stu.getId());
			add(stu);
			
	}
	
	private static Student RsToStu(Student temp,ResultSet rs) throws SQLException {	
			temp.setId(rs.getString(1));
			temp.setName(rs.getString(2));
			temp.setPwd(rs.getString(3));
			temp.setGrade(rs.getString(4));
			temp.setPh_number(rs.getString(5));
			temp.setDirection(rs.getString(6));
			temp.setIntroduce(rs.getString(7));
			temp.setImg(rs.getString(8));
			return temp;
	}
	
}
