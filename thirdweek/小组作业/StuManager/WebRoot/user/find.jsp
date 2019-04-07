<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html>
<html>
<head>
	<base href="<%=basePath%>">
	<meta charset="UTF-8">
	<title>查询界面</title>
	<link rel="stylesheet" type="text/css" href="themes/default/easyui.css">
	<link rel="stylesheet" type="text/css" href="themes/icon.css">
	<link rel="stylesheet" type="text/css" href="css/demo.css">
	<script type="text/javascript" src="js/jquery.min.js"></script>
	<script type="text/javascript" src="js/jquery.easyui.min.js"></script>
</head>
<body>
	<h2>查询界面</h2>
	<p></p>
	<div style="margin:20px 0;"></div>
	<div class="easyui-panel" title="用户查询" style="width:400px;padding:10px 60px 20px 60px">
	<div class="formbody"> 
      <c:choose>
 	<c:when test="${flag == 9 }">
 		<div style="text-align:center;">
       	<span style="font-size:16px;color:red;font-weight:bold;"> 查询的名字或id不存在</span>
       	<c:remove var="flag" />
    	</div>
 	</c:when> 
 	</c:choose>
	<form action="user" method="post" >
		<input type="hidden" name="oper" value = "find" />		
		<table cellpadding="5">	
			<tr>
			<td>请输入要查找的id</td>
				<td><input name="id" class="easyui-validatebox textbox" data-options="required:true,validType:'length[3,10]'" missingMessage="必填"></td>
			</tr>
			<tr>
				<td></td>
				<td><input type="submit" value="查找账号" ></td>
			</tr>
		</table>
	</form>
	</br><br><br>
	<form action="user" method="post" >
		<input type="hidden" name="oper" value = "find"/>		
		<table cellpadding="5">	
			<tr>
			<td>请输入要查找的姓名</td>
				<td><input name="name"  class="easyui-validatebox textbox" data-options="required:true,validType:'length[3,10]'" missingMessage="必填"></td>
			</tr>
			<tr>
				<td></td>
				<td><input type="submit" value="查找账号" ></td>
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