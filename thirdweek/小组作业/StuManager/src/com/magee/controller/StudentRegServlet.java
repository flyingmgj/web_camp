package com.magee.controller;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

public class StudentRegServlet extends HttpServlet {
//	
//	@Override
//	protected void service(HttpServletRequest req, 
//			HttpServletResponse resp) throws ServletException, IOException {
//		//设置编码格式
//		req.setCharacterEncoding("utf-8");
//		resp.setContentType("text/html;charset=utf-8");
//		//获取请求信息
//		
//		//处理请求
//		private String fileUpLoad(HttpServletRequest request , HttpServletResponse response) {
//			if (!ServletFileUpload.isMultipartContent(request)) {
//	            	// 如果不是则停止
//				PrintWriter writer = null;
//				try {
//					writer = response.getWriter();
//				} catch (IOException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
//	            	writer.println("Error: 表单必须包含 enctype=multipart/form-data");
//	            	writer.flush();
//			}
//			String filePath = null;
//			// 配置上传参数
//		        DiskFileItemFactory factory = new DiskFileItemFactory();
//		        // 设置内存临界值 - 超过后将产生临时文件并存储于临时目录中
//		        factory.setSizeThreshold(MEMORY_THRESHOLD);
//		        // 设置临时存储目录
//		        factory.setRepository(new File(System.getProperty("java.io.tmpdir")));
//		 
//		        ServletFileUpload upload = new ServletFileUpload(factory);
//		         
//		        // 设置最大文件上传值
//		        upload.setFileSizeMax(MAX_FILE_SIZE);
//		         
//		        // 设置最大请求值 (包含文件和表单数据)
//		        upload.setSizeMax(MAX_REQUEST_SIZE);
//		        
//		        // 中文处理
//		        upload.setHeaderEncoding("UTF-8"); 
//		
//		        // 构造临时路径来存储上传的文件
//		        // 这个路径相对当前应用的目录
//		        String uploadPath = getServletContext().getRealPath("/") + File.separator + UPLOAD_DIRECTORY;
//		    
//		        // 如果目录不存在则创建
//		        File uploadDir = new File(uploadPath);
//		        if (!uploadDir.exists()) {
//		            uploadDir.mkdir();
//		        } 
//		        try {
//		            // 解析请求的内容提取文件数据
//		            @SuppressWarnings("unchecked")
//		            List<FileItem> formItems = upload.parseRequest(request);
//		            
//		            if (formItems != null && formItems.size() > 0) {
//		                // 迭代表单数据
//		                for (FileItem item : formItems) {
//		                    // 处理不在表单中的字段
//		                    if (!item.isFormField()) {
//		                        String fileName = new File(item.getName()).getName();
//		                        filePath = uploadPath + File.separator + fileName;
//		                        File storeFile = new File(filePath);
//		                        // 在控制台输出文件的上传路径
//		                        System.out.println(filePath);
//		                        // 保存文件到硬盘
//		                        item.write(storeFile);
//		                        request.setAttribute("message",
//		                            "文件上传成功!");
//		                    }
//		                }
//		            }
//		        } catch (Exception ex) {
//		        	request.setAttribute("message","错误信息: " + ex.getMessage());
//		        }    
//		        	        
//		
//		//响应结果
//		}
//	}
}
