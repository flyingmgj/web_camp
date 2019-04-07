package com.magee.dao;

import com.magee.pojo.User;
import com.magee.pojo.User;

public interface UserData {
/**
 * 修改用户信息	
 * @param u   用户信息对象
 * @return
 */
	public boolean modifyInfo(User u);
/**
 * 校验登录
 * @param Id 
 * @param pwd
 * @return
 */
	public User checkInfo(String Id,String pwd);
/**
 * 增加用户	
 * @param u
 * @return
 */
	public boolean add(User u);
/**
 * 删除该id	
 * @param id
 * @return
 */
	public boolean deleteFromId(String id);
/**
 * 查询该id对应的用户	
 * @param id
 * @return
 */
	public User IsIdexist(String id);
}
