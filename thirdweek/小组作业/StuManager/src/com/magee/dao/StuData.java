package com.magee.dao;

import java.util.List;

import com.magee.pojo.Student;

public interface StuData {
	
		public boolean add(Student stu);
		
		public boolean deleteFromId(String id);
		public boolean deleteFromName(String name);
		
		public Student checkInfo(String id,String pwd);
		public Student IsIdexist(String id);
		public Student IsNameexist(String name);		
		public List<Student> getAllInfo();
		public List<String> getAllgrade();
		public List<Student> getgrade(String grade);
		public List<String>  getAllGroup();
		public List<Student>  getGroup(String group);
		public List<String>   getAllId();
		public Student getId(String id);
		
		public void modifyInfo(Student stu);
		
		
}
