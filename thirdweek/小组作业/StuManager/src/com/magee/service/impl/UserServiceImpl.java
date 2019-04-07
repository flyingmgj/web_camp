package com.magee.service.impl;



import java.util.List;

import org.apache.log4j.Logger;

import com.magee.dao.StuData;
import com.magee.dao.UserData;
import com.magee.dao.impl.StuDataImpl;
import com.magee.dao.impl.UserDataImpl;
import com.magee.pojo.Student;
import com.magee.pojo.User;

public class UserServiceImpl implements com.magee.service.UserService{
	//要使用的数据一般都是全局的
	Logger logger = Logger.getLogger(UserServiceImpl.class);
	UserData ud = new UserDataImpl();
	StuData  sd = new StuDataImpl();
	User u = null;
	//用户登录
	@Override
	public User checkUserLoginService(String id, String pwd) {
		logger.debug(id+"@"+pwd+"发起登录请求");
		u = ud.checkInfo(id, pwd);
		if(u != null ) {
			logger.debug(id+"@"+pwd+"管理员登录成功");
		}else {
			logger.debug(id+"@"+pwd+"管理员登录失败");
		}
		return u;
	}

	@Override
	public boolean modifyPwd(User u) {
		logger.debug(u.getId()+"@"+u.getPwd()+"修改密码");
		return ud.modifyInfo(u);
	}

	@Override
	public List<Student> StudentShowService() {
		logger.debug("查询所有用户信息");
		return sd.getAllInfo();
	}
	
}
