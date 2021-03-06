package com.magee.until;

import java.util.HashMap;
import java.util.Map;

import org.apache.commons.fileupload.FileItem;
 
public class ParamDto {
 
    private Map<String,String> paramMap;
    private Map<String,FileItem> fileMap;
 
    public ParamDto() {
        paramMap = new HashMap<>();
        fileMap = new HashMap<>();
    }
 
    public Map<String, String> getParamMap() {
        return paramMap;
    }
 
    public void setParamMap(Map<String, String> paramMap) {
        this.paramMap = paramMap;
    }
 
    public Map<String, FileItem> getFileMap() {
        return fileMap;
    }
 
    public void setFileMap(Map<String, FileItem> fileMap) {
        this.fileMap = fileMap;
    }
}
