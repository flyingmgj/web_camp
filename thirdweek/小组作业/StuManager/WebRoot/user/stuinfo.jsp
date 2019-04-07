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
	<title>个人信息</title>
	<link href="css/style.css" rel="stylesheet" type="text/css" />
</head>

<body>

    <div class="formbody"> 
      <c:choose>
 	<c:when test="${flag == 7 }">
 		<div style="text-align:center;">
       	<span style="font-size:16px;color:red;font-weight:bold;">修改基本信息成功</span>
       	<c:remove var="flag" />
    	</div>
 	</c:when>
 	<c:when test="${flag == 8 }">
 		<div style="text-align:center;">
       	<span style="font-size:16px;color:red;font-weight:bold;">修改密码成功</span>
       	<c:remove var="flag" />
    	</div>
 	</c:when>  
     </c:choose>
    <div class="formtitle"><span>基本信息</span></div>
    
    <ul class="forminfo">  
   
    <li> <img/ src="" > </li>
    <li><label>id</label><i><c:out value="${stu.getId() }"></c:out></i></li>
    <li><label>姓名</label><i><c:out value="${stu.getName() }"></c:out></i></li>
    <li><label>专业</label><i></i><c:out value="${stu.getPh_number() }"></c:out></li>
    <li><label>手机号码</label><i><c:out value="${stu.getGrade() }"></c:out></i></li>
    <li><label>方向</label><i><c:out value="${stu.getDirection() }"></c:out></i></li>
    <li><label>个人介绍</label><i></i><c:out value="${stu.getIntroduce() }"></c:out></li>
    <li><label>&nbsp;</label><a href="/pro/stu/modify.jsp">修改信息</a></li>
    <li><label>&nbsp;</label><a href="/pro/stu/pwd.jsp?useroper=1" >修改密码</a></li>
    </ul>
    
    
    </div>


</body>

</html>