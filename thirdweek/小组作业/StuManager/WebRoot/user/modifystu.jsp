<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html>
<html>
<head>
	<base href="<%=basePath%>">
	<meta charset="UTF-8">
	<title>修改用户信息</title>
	<link rel="stylesheet" type="text/css" href="themes/default/easyui.css">
	<link rel="stylesheet" type="text/css" href="themes/icon.css">
	<link rel="stylesheet" type="text/css" href="css/demo.css">
	<script type="text/javascript" src="js/jquery.min.js"></script>
	<script type="text/javascript" src="js/jquery.easyui.min.js"></script>
</head>
<body>
	<h2>修改界面</h2>
	<p></p>
	<div style="margin:20px 0;"></div>
	<div class="easyui-panel" title="用户修改" style="width:400px;padding:10px 60px 20px 60px">
	<form action="user" method="post" >
		<input type="hidden" name="oper" value = "reg"/>
		<input type="hidden" name="useroper" value = "reg"/>
		<% 
	    		//修改的提示语
	    		Object reg = session.getAttribute("regError") ;
	    		if(reg != null ) {
	    	%>
	    		<div style="text-align:center;">
	       		<span style="font-size:16px;color:red;font-weight:bold;">该id已经存在</span>
	    		</div>
			<% }
				session.removeAttribute("regError");
			%>
		<table cellpadding="5">	
			<tr>
				<td>id:</td>
				<td></td>
			</tr>
			<tr>
				<td>密码</td>
				<td><input name="pwd" class="easyui-validatebox textbox" data-options="required:true,validType:'length[3,10]'"missingMessage="必填"></td>
			</tr>
			<tr>
				<td>姓名</td>
				<td><input name="name" value="" class="easyui-validatebox textbox" ></td>
			</tr>
			<tr>
				<td>班级</td>
				<td><input name="grade" value="" class="easyui-validatebox textbox" ></td>
			</tr>			
			<tr>
				<td>手机号码</td>
				<td><input name="ph_number" value="" class="easyui-validatebox textbox" data-options="required:true validType:'length[8,11]'"></td>
			</tr>
			<tr>
				<td>方向</td>
				<td><input name="direction" value="" class="easyui-validatebox textbox" ></td>
			</tr>
			<tr>
				<td>个人介绍</td>
				<td><input name="introduce" value="" class="easyui-validatebox textbox" ></td>
			</tr>
			<tr>
				<td>头像（选择图片）</td>
				<td><input name="photo" type="file" name="photo" ></td>
			</tr>
			<tr>
				<td></td>
				<td><input type="submit" value="注册账号" ></td>
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
