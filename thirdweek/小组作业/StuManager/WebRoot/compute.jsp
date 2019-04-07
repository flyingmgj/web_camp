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
	<title>Load Form Data - jQuery EasyUI Demo</title>
	<link rel="stylesheet" type="text/css" href="../../themes/default/easyui.css">
	<link rel="stylesheet" type="text/css" href="../../themes/icon.css">
	<link rel="stylesheet" type="text/css" href="../demo.css">
	<script type="text/javascript" src="../../jquery.min.js"></script>
	<script type="text/javascript" src="../../jquery.easyui.min.js"></script>
</head>
<body>
	<h2>四则运算简易版</h2>
	<p></p>
	<div style="margin:20px 0;">
		<a href="javascript:void(0)" class="easyui-linkbutton" onclick="loadLocal()"></a>
		<a href="javascript:void(0)" class="easyui-linkbutton" onclick="loadRemote()"></a>
		<a href="javascript:void(0)" class="easyui-linkbutton" onclick="clearForm()"></a>
	</div>
	    <form action="/pro/compute" id="ff" method="post">
	    <% 
    		//判断密码校验是否正确
    		Object obj = request.getAttribute("error") ;
    		if(obj != null ) {
    	%>
    		<div style="text-align:center;">
       		<span style="font-size:16px;color:red;font-weight:bold;">表达式有误</span>
    		</div>
		<% 
			request.removeAttribute("error");
		} %>
	    	<table cellpadding="5">
	    		<tr>
	    			<td>请输入要计算的表达式</td>
	    			<td><input class="easyui-validatebox textbox" type="text" name="expression" data-options="required:true"></input></td>
	    		</tr>
	    		<tr>
	    			<td>计算结果为</td>
	    	<% 
	    		Object obj2 = request.getAttribute("result");
	    		if(obj2 != null) {
	    	%>	
	    		<td><%=  ((int)request.getAttribute("result")) %></td>	
	    			    	
	    	<% }%>
	    			
	    		</tr>
	    		<tr>
	    			<td>提交表达式</td>
	    			<td><input class="easyui-validatebox textbox" type="submit" ></input></td>
	    		</tr>
	    	</table>
	    </form>
	    </div>
	</div>
</body>
</html>