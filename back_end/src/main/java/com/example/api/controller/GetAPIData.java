package com.example.api.controller;

import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.web.client.RestTemplate;


class ResponseResult<T> {
    public boolean status;  // 响应状态，true 表示成功，false 表示失败
    public int code;        // 状态码，例如 200 表示成功，非 200 表示失败
    public String msg;      // 状态信息，例如成功或者失败的提示信息
    public T data;          // 具体数据类型，由接口决定

}

public class GetAPIData {
    public static ResponseResult<String> mydata(String url, String apikey) {

        ResponseResult<String> responseResult = new ResponseResult<>();

        RestTemplate restTemplate = new RestTemplate();
        HttpHeaders headers = new HttpHeaders();
        headers.set("api-key", apikey);
        HttpEntity<String> entity = new HttpEntity<>(headers);
        try {
            ResponseEntity<String> response = restTemplate.exchange(url, HttpMethod.GET, entity, String.class);
            responseResult.status = true;
            responseResult.code = 200;
            responseResult.data = response.getBody();
            System.out.println(response.getBody());
        } catch (Exception e) {
            responseResult.status = false;
            responseResult.code = 500;
            System.out.println(e);
        }
        return responseResult;
    }
}
