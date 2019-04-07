package com.magee.controller;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Iterator;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Part;

import org.apache.log4j.Logger;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import com.magee.pojo.Student;
import com.magee.pojo.User;
import com.magee.service.StudentService;
import com.magee.service.UserService;
import com.magee.service.impl.StudentServiceImpl;
import com.magee.service.impl.UserServiceImpl;
import com.magee.until.ParamDto;
import com.magee.until.RequestUtil;


public class UserServlet extends HttpServlet {
	
//全局变量（属性）的声明
	Logger logger = Logger.getLogger(UserServlet.class);
	UserService us  = new UserServiceImpl(); 
	StudentService ss = new StudentServiceImpl(); 
	 
	 @Override
	protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		 req.setCharacterEncoding("utf-8");
		 resp.setContentType("text/html;charset=utf-8");
		 //调用相应的方法
		 //登陆请求
		 //获取操作符
		 String oper = req.getParameter("oper");   
		//判断表单属性--如果是文件类型则对应解析
		 if(ServletFileUpload.isMultipartContent(req)) {
			 //文件传输类型--相关处理
			 //封装类对象paramDto-----工具类解析
			 ParamDto dto = RequestUtil.parseParam(req);
			//普通表单----键值对
			String id = dto.getParamMap().get("id");
			String name = dto.getParamMap().get("name");
			String pwd = dto.getParamMap().get("pwd");
			String grade = dto.getParamMap().get("grade");
			String ph_number = dto.getParamMap().get("ph_number");
			String direction = dto.getParamMap().get("direction");
			String introduce = dto.getParamMap().get("introduce");			
			
			//文件内容
			//获取文件，并保存---到服务器
			FileItem item = dto.getFileMap().get("photo");
			//获取文件原始名称
			String filepath = item.getName();
			//获取文件保存在服务器的路径---相对路径
			String path = this.getServletContext().getRealPath("/photo");
			//保存图片
			try {
				item.write(new File(path + filepath));
			} catch (Exception e) {
				System.out.println("下载文件时失败");
			}
			
			//调用注册功能-
			Student stu = new Student(id, name, pwd, grade, ph_number, direction, introduce, path+filepath); 
			UserReg(req, resp, stu);
			return ;
		 }
		 //处理
		 if("login".equals(oper)) { 
			 //登录请求
			 //获取身份的数据--判断对应的处理方法
			 if(req.getParameter("identity").equals("user")) {
				 checkUserLogin(req, resp);
			 }else {
				 checkStuLogin(req,resp);
			 }
		 }else if("out".equals(oper) ){
			 //退出功能
			 UserOut(req,resp);
		 }else if("newPwd".equals(oper) ){
			 //修改密码功能--管理员
			 UserChangePwd(req,resp);
		 }else if("find".equals(oper) ){
			 //查找用户功能--管理员
			 StudentFind(req,resp);
		 }else if("newPwdstu".equals(oper) ){
			 //修改密码功能--学生
			 StudentChangePwd(req,resp);
		 }else if("modifyInfo".equals(oper) ){
			 //修改用户基本信息-
			 StudentChangeInfo(req,resp);
		 }else if("show".equals(oper)){
			 //查询s所有用户功能
			 StudentShow(req,resp);
		 }else if("delete".equals(oper)){
			 //注销用户
			 
			 Studentdelete(req,resp);
		 }else {
			 
			 logger.debug("未找到对应操作符"+oper);		
		 }
	}
	 
	 
private void StudentFind(HttpServletRequest req, HttpServletResponse resp) {
		// 查找某个学生信息-------管理员功能
		String name = req.getParameter("name");
		String id = req.getParameter("id");
		HttpSession hs = req.getSession();
		System.out.println(id+"@"+name);
		if(null != id) {
			//id查询
			//创建业务层对象
			Student stu = ss.findStudentFromID(id);
			if(null != stu) {
				//查询到该用户----重定向到用户信息界面				
				hs.setAttribute("stu", stu);
				try {
					resp.sendRedirect("/pro/user/stuinfo.jsp");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					//错误界面
				}
			}else {
				//未查询到该用户--重定向回去--并返回一条用户不存在的信息
				hs.setAttribute("flag", 9);
				try {
					resp.sendRedirect("/pro/user/find.jsp");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					//错误界面
				}
			}
			
		}else if(null != name) {
			//姓名查询
			//创建业务层对象
			Student stu = ss.findStudentFromName(name);
			if(null != stu) {
				//查询到该用户----重定向到用户信息界面				
				hs.setAttribute("stu", stu);
				try {
					resp.sendRedirect("/pro/user/stuinfo.jsp");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					//错误界面
				}
			}else {
				//未查询到该用户--重定向回去--并返回一条用户不存在的信息
				hs.setAttribute("flag", 9);
				try {
					resp.sendRedirect("/pro/user/find.jsp");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					//错误界面
				}
			}
		}
	}


private void Studentdelete(HttpServletRequest req, HttpServletResponse resp) {
		//获取信息
			String id = req.getParameter("id");
		//业务层
			 boolean yes = ss.deleteStudent(id);
		if(yes == true ) {
			//删除成功重定向回到删除界面
			HttpSession hs = req.getSession();
			hs.setAttribute("deleteSuccess", true);
			hs.setAttribute("flag", 5);
			try {
				resp.sendRedirect("/pro/user/deletestu.jsp");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//错误界面
			}
			return ;
		}else {
			//删除失败--不存在该id
			//删除成功重定向回到删除界面
			HttpSession hs = req.getSession();
			hs.setAttribute("deleteError", true);
			hs.setAttribute("flag",6);
			try {
				resp.sendRedirect("/pro/user/deletestu.jsp");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//错误界面
			}
			return ;
		}
	}


private void StudentChangePwd(HttpServletRequest req, HttpServletResponse resp) {
		//获取信息
		HttpSession hs = req.getSession();
		Student stu = (Student)hs.getAttribute("stu");
		String newpwd = req.getParameter("newPwd");
		if(stu == null ) {	//session信息已经失效---需要重定向到登录页面
			hs.setAttribute("valid", true);
			try {
				resp.sendRedirect("/pro/login.jsp");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//跳转到错误界面
			}
		}else {
			//修改密码
				stu.setPwd(newpwd);
			//获取业务层对象
				ss.modifyStudentInfo(stu);
				logger.debug(stu.getId()+"@"+stu.getPwd()+"修改密码成功");
				//重定向到登录界面界面
				if(req.getSession().getAttribute("useroper") != null) {
					//如果是管理员修改密码则重定向回个人信息界面
					try {
						//标识了是重定向到login界面---
						hs.setAttribute("flag", 8);
						resp.sendRedirect("/pro/user/stuinfo.jsp");
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						//错误界面
						
					}
				}
				try {
					//标识了是重定向到login界面---
					hs.setAttribute("flag", 2);
					resp.sendRedirect("/pro/login.jsp");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					//错误界面
					
				}
		}
	}


private void StudentChangeInfo(HttpServletRequest req, HttpServletResponse resp) throws IOException {
		//获取信息
		String name = req.getParameter("name");
		String grade = req.getParameter("grade");
		String ph_number = req.getParameter("ph_number");
		String direction = req.getParameter("direction");
		String introduce = req.getParameter("introduce");
		//待处理的头像问题
		String img	= req.getParameter("photo");
		HttpSession hs = req.getSession();
		Student a = (Student)hs.getAttribute("stu");
		Student stu = new Student(a.getId(), name, a.getPwd(), grade, ph_number, direction, introduce, img);
		//业务层处理
		logger.debug(stu.getId()+"@"+stu.getPwd()+"修改个人信息");
		ss.modifyStudentInfo(stu); 
		hs.setAttribute("flag", 4);
		hs.setAttribute("stu", stu);
		resp.sendRedirect("/pro/stu/stuinfo.jsp");
	}


private void UserReg(HttpServletRequest req, HttpServletResponse resp,Student stu) throws UnsupportedEncodingException {
	//获取请求信息 
//	  String id = req.getParameter("id");
//	  String name = req.getParameter("name");
//	  String pwd = req.getParameter("pwd");
//	  String grade = req.getParameter("grade");
//	  String ph_number = req.getParameter("ph_number");
//	  String introduce = req.getParameter("introduce");
//	  String direction = req.getParameter("ph_number");
//	   String img ="";
		  logger.debug(stu.getId()+"@"+stu.getPwd()+"@"+stu.getName()+"请求注册新账户");	
//		  Student stu = new Student(id, name, pwd, grade, ph_number, direction, introduce, img);
		  //处理请求信息
		  	//上传文件处理
		  	//调用业务层处理 
		  boolean check = ss.studentRegService(stu);
		  if(check) {
			  if(req.getParameter("useroper") != null) {
				  //重定向到注册界面-----此处为由管理员添加账号
				//注册成功重定向到注册界面
				  //发送id重复的消息
				  HttpSession hs =req.getSession();
				  hs.setAttribute("flag", 4);
				  try {
					resp.sendRedirect("/pro/user/reg.jsp");
					return ;
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					//错误界面的提示
					
				}
			  }
			  
			  //注册成功重定向到登录界面
			  //发送注册成功的消息
			  HttpSession hs =req.getSession();
			  hs.setAttribute("flag", 3);
			  try {
				resp.sendRedirect("/pro/login.jsp");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//错误界面的提示
				
			}
			  
		  }else {
			  //注册失败重定向到注册界面
			  //发送id重复的消息
			  HttpSession hs =req.getSession();
			  hs.setAttribute("flag", 6);
			  try {
				resp.sendRedirect("/pro/user/reg.jsp");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//错误界面的提示
				
			}
			  
		  }
	}


private void StudentShow(HttpServletRequest req, HttpServletResponse resp) {
		//调用service处理请求
		List<Student> lstu = us.StudentShowService(); 
		
		if(lstu != null) {
			//使用请求转发
			req.setAttribute("lstu", lstu);
			try {
				req.getRequestDispatcher("/user/showStu.jsp").forward(req, resp);
				return ;
			} catch (ServletException | IOException e) {
				e.printStackTrace();
				//错误界面
			}
		}
	}


private void UserChangePwd(HttpServletRequest req, HttpServletResponse resp) {
		//获取新密码--用户信息
		String newPwd = req.getParameter("newPwd");
		User u = (User) req.getSession().getAttribute("user");
		u.setPwd(newPwd);
		//处理请求
			//修改密码
			boolean bl = us.modifyPwd(u);
			
			if(bl != false) {
				//重定向到登录界面界面
				try {
					//获取session对象
					HttpSession hs = req.getSession();
					//标识了是重定向到login界面---
					hs.setAttribute("flag", 2);
					resp.sendRedirect("/pro/login.jsp");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					//错误界面
					
				}
			}else {
				//修改失败
			}
	}


private void UserOut(HttpServletRequest req, HttpServletResponse resp) {
		//销毁session对象--完善退出功能
		HttpSession hs = req.getSession();
		hs.invalidate();
		//重定向到登录页面
		try {
			resp.sendRedirect("/pro/login.jsp");
			logger.debug("退出登录");
		} catch (IOException e) {
			e.printStackTrace();
		//返回错误界面
		}
		
	}


/**
 * 	处理登录的方法
 * @param req
 * @param resp
 */
	private void checkStuLogin(HttpServletRequest req, HttpServletResponse resp) {
		//获取请求数据
		String id = req.getParameter("id");
		String pwd = req.getParameter("pwd");
		//校验
		Student stu = ss.checkStudentLoginService(id,pwd);
		if(stu != null){ //登录成功
			System.out.println(stu.toString());
			//跳转页面操作
			try {
				//获取session对象 
				HttpSession hs = req.getSession();
				hs.setAttribute("stu", stu);
				resp.sendRedirect("/pro/stu/stuinfo.jsp");
				return ;
			} catch (IOException e) {
				e.printStackTrace();
				//重定向到一个错误提示的界面
			}
		}else { //登录失败
			
			//添加表示符
			req.getSession().setAttribute("flag", 1);
			
			try {
				resp.sendRedirect("/pro/login.jsp");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//错误界面 
			}
			
			return ;
		}
	}
/**
 *  commons io fileupload
 * @param req
 * @param resp
 */
	private void checkUserLogin(HttpServletRequest req, HttpServletResponse resp) {
		//获取请求数据
		String id = req.getParameter("id");
		String pwd = req.getParameter("pwd");
		
		//校验
		User u = us.checkUserLoginService(id, pwd);
		if(u != null){ //登录成功
			System.out.println(u.toString());
			//跳转页面操作
			try {
				//获取session对象 
				HttpSession hs = req.getSession();
				hs.setAttribute("user", u);
				resp.sendRedirect("/pro/main/main.jsp");
				return ;
			} catch (IOException e) {
				e.printStackTrace();
				//重定向到一个错误提示的界面
			}
		}else { //登录失败
			
			//添加表示符
			req.getSession().setAttribute("flag", 1);
			try {
				resp.sendRedirect("/pro/login.jsp");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//错误界面 
			}
			
			return ;
		}		
	}
	

}
