package com.magee.pojo;

public class Student {
	private String id ;
	private String name;
	private String pwd;
	private String grade;
	private String ph_number;
	private String direction;
	private String introduce;
	private String img;
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPwd() {
		return pwd;
	}
	public void setPwd(String pwd) {
		this.pwd = pwd;
	}
	public String getGrade() {
		return grade;
	}
	public void setGrade(String grade) {
		this.grade = grade;
	}
	public String getPh_number() {
		return ph_number;
	}
	public void setPh_number(String phone) {
		this.ph_number = phone;
	}
	public String getDirection() {
		return direction;
	}
	public void setDirection(String direction) {
		this.direction = direction;
	}
	public String getIntroduce() {
		return introduce;
	}
	public void setIntroduce(String introduce) {
		this.introduce = introduce;
	}
	public String getImg() {
		return img;
	}
	public void setImg(String img) {
		this.img = img;
	}
	public Student() {
		super();
	}
	public Student(String id, String name, String pwd, String grade, String ph_number, String direction,
			String introduce, String img) {
		super();
		this.id = id;
		this.name = name;
		this.pwd = pwd;
		this.grade = grade;
		this.ph_number = ph_number;
		this.direction = direction;
		this.introduce = introduce;
		this.img = img;
	}
	
}
