package com.magee.listener;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

/**
 * 监听器实现在线人数记录
 * @author Administrator
 *
 */
public class MyListener implements HttpSessionListener,ServletContextListener{
//
	@Override
	public void contextDestroyed(ServletContextEvent sce) {
	}

	@Override
	public void contextInitialized(ServletContextEvent sce) {
		//获取appliction
		ServletContext sc = sce.getServletContext();
		//设置对象
		sc.setAttribute("number", 0);
	}
//session监听对象
	@Override
	public void sessionCreated(HttpSessionEvent se) {
		//获取servletContext对象
		ServletContext sc = se.getSession().getServletContext();
		//获取在线人数
		int num = (int)sc.getAttribute("number");
		sc.setAttribute("number", ++num);
	}

	@Override
	public void sessionDestroyed(HttpSessionEvent se) {
		//获取servletContext对象
				ServletContext sc = se.getSession().getServletContext();
				//获取在线人数
				int num = (int)sc.getAttribute("number");
				sc.setAttribute("number", --num);
	}
	
}
