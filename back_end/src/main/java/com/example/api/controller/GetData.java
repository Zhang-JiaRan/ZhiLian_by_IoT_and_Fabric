package com.example.api.controller;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")
public class GetData {
    @GetMapping("/tracking")
    @CrossOrigin
    public ResponseResult<String> GetData(){
//        List<MySQL> list = myMapper.find();
        ResponseResult<String> myData = GetAPIData.mydata("http://api.heclouds.com/devices/965775756/datapoints?","2UxdSKWjuVxUJ6WconRae==RtKo=");
//        MySQL mysql = new MySQL();
//        mysql.setCno("7");
//        mysql.setCname("LCJ");
//        myMapper.insert(mysql);
        return myData;
    }
}
