<%@ page language="java" import="java.util.*,com.magee.pojo.*" pageEncoding="utf-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<base href="<%=basePath%>">
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>个人信息</title>
	<link href="css/style.css" rel="stylesheet" type="text/css" />
</head>

<body>

    <div class="formbody"> 
      <c:choose>
 	<c:when test="${flag == 4 }">
 		<div style="text-align:center;">
       	<span style="font-size:16px;color:red;font-weight:bold;">修改成功</span>
       	<c:remove var="flag" />
    	</div>
 	</c:when>  
   </c:choose> 
    <div class="formtitle"><span>基本信息</span></div>
    
    <ul class="forminfo"> 
    <% 
    	Student stu =(Student)session.getAttribute("stu");
    	if(stu == null) {
    		response.sendRedirect("/pro/login.jsp");
    	}
    %>
    
    <img/ src="<c:out value="/${img}"></c:out>">
    <li><label>id</label><i><%= stu.getId()%><c:out value="${stu.getId() }"></c:out></i></li>
    <li><label>姓名</label><i><%= stu.getName()%></i></li>
    <li><label>专业</label><i><%= stu.getGrade()%></i></li>
    <li><label>手机号码</label><i><%= stu.getPh_number()%></i></li>
    <li><label>方向</label><i><%= stu.getDirection()%></i></li>
    <li><label>个人介绍</label><i><%= stu.getIntroduce()%></i></textarea></li>
    <li><label>&nbsp;</label><a href="/pro/stu/modify.jsp">修改个人信息</a></li>
    <li><label>&nbsp;</label><a href="/pro/stu/pwd.jsp" ">修改密码</a></li>
    </ul>
    
    
    </div>


</body>

</html>