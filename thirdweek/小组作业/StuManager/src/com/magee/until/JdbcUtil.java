package com.magee.until;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JdbcUtil {
	public static Connection getMysqlConn() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			return (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/testjdbc?useUnicode=true&characterEncoding=UTF-8&zeroDateTimeBehavior=convertToNull","root","123");
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}
	
/**
 * close resource	
 * @param rs
 * @param stmt
 * @param conn
 */
	public static void close(ResultSet rs ,Statement stmt, Connection conn) {
		try {
			if(null != rs )rs.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		close(stmt, conn);
	}
/**
 * close resource		
 * @param stmt
 * @param conn
 */
	public static void close(Statement stmt, Connection conn) {
		try {
			if(null != stmt )stmt.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		close(conn);
	}
/**
 * close resource	
 * @param conn
 */
	public static void close( Connection conn) {
		try {
			if(null != conn )conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
