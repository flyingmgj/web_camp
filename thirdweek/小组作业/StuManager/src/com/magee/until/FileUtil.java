package com.magee.until;

import java.io.File;

import org.apache.commons.fileupload.FileItem;

public class FileUtil {
	 
    /**
     * 上传文件的保存路径
     */
    public static final String SAVE_PATH = "F:/Desktop/pic/";
 
    /**
     * 保存上传的文件
     * @param fileItem
     * @param path
     * @return
     * @throws Exception
     */
    public static String save(FileItem fileItem,String path) throws Exception {
        String fileName = System.currentTimeMillis() + "_" + fileItem.getName();
        fileItem.write(new File(path + fileName));
        return fileName;
    }
}
