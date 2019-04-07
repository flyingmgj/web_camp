package com.magee.service.impl;

import org.apache.log4j.Logger;

import com.magee.dao.*;
import com.magee.dao.impl.*;
import com.magee.pojo.Student;
import com.magee.service.StudentService;

public class StudentServiceImpl implements StudentService{
	StuData sd = new StuDataImpl();
	Logger logger = Logger.getLogger(UserServiceImpl.class);
	@Override
	public boolean studentRegService(Student stu) {
		boolean a;
			if(sd.IsIdexist(stu.getId()) != null) {
				 logger.debug(stu.getId()+"@"+stu.getPwd()+"id重复注册失败");
				 return false;				
			}
			else 
			logger.debug(stu.getId()+"@"+stu.getPwd()+"注册成功");	
			return sd.add(stu);
	}
	@Override
	public Student checkStudentLoginService(String id, String pwd) {
		if(sd.checkInfo(id, pwd) != null) {
			logger.debug(id+"@"+pwd+"用户登录成功");
		}else {
			logger.debug(id+"@"+pwd+"用户登录失败");
		}
		return sd.checkInfo(id, pwd);
	}
	@Override
	public void modifyStudentInfo(Student stu) {
			sd.modifyInfo(stu);
		return ;
	}
	@Override
	public boolean deleteStudent(String id) {
		
		return sd.deleteFromId(id);
	}
	@Override
	public Student findStudentFromID(String id) {
		
		return sd.IsIdexist(id);
	}
	@Override
	public Student findStudentFromName(String name) {
		
		return sd.IsNameexist(name);
	}
	
}
