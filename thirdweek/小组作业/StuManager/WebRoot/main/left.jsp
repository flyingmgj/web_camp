<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<base href="<%=basePath%>">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title></title>
<link href="css/style.css" rel="stylesheet" type="text/css" />
<script language="JavaScript" src="js/jquery.js"></script>

<script type="text/javascript">
$(function(){	
	//导航切换
	$(".menuson .header").click(function(){
		var $parent = $(this).parent();
		$(".menuson>li.active").not($parent).removeClass("active open").find('.sub-menus').hide();
		
		$parent.addClass("active");
		if(!!$(this).next('.sub-menus').size()){
			if($parent.hasClass("open")){
				$parent.removeClass("open").find('.sub-menus').hide();
			}else{
				$parent.addClass("open").find('.sub-menus').show();	
			}
			
			
		}
	});
	
	// 三级菜单点击
	$('.sub-menus li').click(function(e) {
        $(".sub-menus li.active").removeClass("active")
		$(this).addClass("active");
    });
	
	$('.title').click(function(){
		var $ul = $(this).next('ul');
		$('dd').find('.menuson').slideUp();
		if($ul.is(':visible')){
			$(this).next('.menuson').slideUp();
		}else{
			$(this).next('.menuson').slideDown();
		}
	});
})	
</script>


</head>

<body style="background:#fff3e1;">
	<div class="lefttop"><span></span>管理员功能</div>
    
    <dl class="leftmenu">
        
    <dd>
    <div class="title">
    <span><img src="images/leftico01.png" /></span>功能选择
    </div>
    	<ul class="menuson">
        
        <li>
            <div class="header">
            <cite></cite>
            <a  target="rightFrame">管理信息</a>
            <i></i>
            </div>
            <ul class="sub-menus">
            <li><a href="user/addstu.jsp" target="rightFrame">新增学生账号</a></li>
            <li><a href="user/deletestu.jsp" target="rightFrame">注销学生账号</a></li>
            <li><a href="user/modifystu.jsp" target="rightFrame">修改学生信息</a></li>
            <li><a href="user/find.jsp" target="rightFrame">查询</a>
	   <li><a href="user?oper=show" target="rightFrame">查看所有学生信息</a></li>
    
            </li>       
            </ul>
        </li>
        

        
        <li><cite></cite><a href="user/userinfo.jsp" target="rightFrame">查询个人信息</a><i></i></li>
		<li><cite></cite><a href="user/pwd.jsp" target="rightFrame">修改密码</a><i></i></li>
        </ul>    
    </dd>
 
    </dl>
    
</body>
</html>
    