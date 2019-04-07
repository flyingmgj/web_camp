<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
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
    <div class="formtitle"><span>基本信息</span></div>
    
    <ul class="forminfo">
    <form action="user" method="post">
    <input type="hidden" name="oper" value = "modifyInfo"/>
    <img/>
    <li><label>id</label><i></i><c:out value="${stu.getId()}"></c:out></li>
    <li><label>姓名</label><input name="name" type="text" class="dfinput" /></li>
    <li><label>专业</label><input name="grade" type="text"  class="dfinput"/></li>
    <li><label>手机号码</label><input name="ph_number" type="text" class="dfinput" /></li>
    <li><label>方向</label><input name="direction" type="text" class="dfinput" /></li>
    <li><label>个人介绍</label><textarea name="introduce" cols="" rows="" class="textinput"></textarea></li>
    <li><label>头像选择</label><input name="photo" type="file" name="photo"  value=""></li>
    <li><label>&nbsp;</label><input type="submit"  value="保存"/></li>
    </ul>
    </form>
    
    </div>


</body>

</html>