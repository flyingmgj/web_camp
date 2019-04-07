package com.magee.service;

import com.magee.pojo.Student;

public interface StudentService {

	boolean studentRegService(Student stu);

	Student checkStudentLoginService(String id, String pwd);

	void modifyStudentInfo(Student stu);

	boolean deleteStudent(String id);

	Student findStudentFromID(String id);

	Student findStudentFromName(String name);
	
}
