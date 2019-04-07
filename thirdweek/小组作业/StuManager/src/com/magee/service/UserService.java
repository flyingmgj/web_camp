package com.magee.service;

import java.util.List;

import com.magee.pojo.Student;
import com.magee.pojo.User;
public interface UserService {
	/**
	 * 管理员校验
	 * @param name
	 * @param pwd
	 * @return
	 */
	User checkUserLoginService(String name, String pwd);
	boolean modifyPwd(User u);
	List<Student>  StudentShowService();
}
