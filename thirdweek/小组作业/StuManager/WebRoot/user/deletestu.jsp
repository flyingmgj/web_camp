<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html>
<html>
<head>
	<base href="<%=basePath%>">
	<meta charset="UTF-8">
	<title>删除界面</title>
	<link rel="stylesheet" type="text/css" href="themes/default/easyui.css">
	<link rel="stylesheet" type="text/css" href="themes/icon.css">
	<link rel="stylesheet" type="text/css" href="css/demo.css">
	<script type="text/javascript" src="js/jquery.min.js"></script>
	<script type="text/javascript" src="js/jquery.easyui.min.js"></script>
</head>
<body>
	<h2>删除界面</h2>
	<p></p>
	<div style="margin:20px 0;"></div>
	<div class="easyui-panel" title="用户删除" style="width:400px;padding:10px 60px 20px 60px">
	<form action="user" method="post" >
		<input type="hidden" name="oper" value = "delete"/>
		<c:choose>
			<c:when test="${flag==5}">
				<div style="text-align:center;">
	       		<span style="font-size:16px;color:red;font-weight:bold;">删除成功</span>
	    		</div>
	    		<c:remove var="flag"/>
			</c:when>
			<c:when test="${flag==6}">
				<div style="text-align:center;">
	       		<span style="font-size:16px;color:red;font-weight:bold;">该id不存在</span>
	    		</div>
	    		<c:remove var="flag"/>
			</c:when>
		</c:choose>
		
		 <table cellpadding="5">	
			<tr>
				<td>请选择你要删除的id</td>
				<td><input name="id" class="easyui-validatebox textbox" data-options="required:true,validType:'length[3,10]'" missingMessage="必填"></td>
			</tr>

			<tr>
				<td></td>
				<td><input type="submit" value="删除该账号" ></td>
			</tr>
		</table>
	</form>
	</div>
	<style scoped="scoped">
		.textbox{
			height:20px;
			margin:0;
			padding:0 2px;
			box-sizing:content-box;
		}
	</style>

</body>
</html>
