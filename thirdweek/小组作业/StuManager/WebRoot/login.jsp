<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%> 

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
 <base href="<%=basePath%>">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>迎新系统</title>
<link href="css/style.css" rel="stylesheet" type="text/css" />
<script language="JavaScript" src="js/jquery.js"> </script>
<script src="js/cloud.js" type="text/javascript"> </script>

<script language="javascript">
	$(function(){
    $('.loginbox').css({'position':'absolute','left':($(window).width()-692)/2});
	$(window).resize(function(){  
    $('.loginbox').css({'position':'absolute','left':($(window).width()-692)/2});
    })  
});  
</script> 

</head>

<body style="background-color:#df7611; background-image:url(images/light.png); background-repeat:no-repeat; background-position:center top; overflow:hidden;">



    <div id="mainBody">
      <div id="cloud1" class="cloud"></div>
      <div id="cloud2" class="cloud"></div>
    </div>  


<div class="logintop">    
    <span>欢迎进入迎新系统登录/注册界面</span>     
    </div>
    
    <div class="loginbody">
    
    <span class="systemlogo"></span> 
    	<br/ >
    	<!-- 使用JSTL和eL表达式 -->
    	<c:choose>
    		<c:when test="${flag==1}">
    			<div style="text-align:center;">
       			<span style="font-size:16px;color:red;font-weight:bold;">用户名/密码错误</span>
    			</div>
    			<c:remove var="flag"/>
    		</c:when>
    		<c:when test="${flag==2}">
    			<div style="text-align:center;">
       			<span style="font-size:16px;color:red;font-weight:bold;">密码修改成功</span>
    			</div>
    			<c:remove var="flag"/>
    		</c:when>
    		<c:when test="${flag==3}">
    			<div style="text-align:center;">
       			<span style="font-size:16px;color:red;font-weight:bold;">注册成功</span>
    			</div>
    			<c:remove var="flag"/>
    		</c:when>
    	</c:choose>  	
    <div class="loginbox loginbox1">
    	
    <form action="/pro/user" method='post'>
    	<input type="hidden" name="oper" value = "login"/> 
    	<ul>
    	<li><input name="id" type="text" placehoder="id" class="loginuser" /></li>
    	<li><input name="pwd" type="password" placehoder="pwd" class="loginpwd" /></li>
    	
    	<li>
    		<select name="identity">
			<option value="student">学生</option>
			<option value="user">管理员</option>	    	
    		</select>
    	</li>
   	 	<li><input  type="submit" class="loginbtn" value="登录"  />
   	 	<label><a href="user/reg.jsp">注册</a></label>
   	 	<label><a >忘记密码？</a></label></li>
    	</ul>
    </form>
    
    </div>
    
    </div>
    
</body>

</html>
    