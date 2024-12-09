

Page({
  data: {
    temp:0,
    humi:0,
    cong:0,
    dagang:0
   },

   // 事件处理函数
   getinfo(){
    var that = this
    wx.request({
    url: "http://api.heclouds.com/devices/965775756/datapoints",   
    //将请求行中的数字换成自己的设备ID
    header: {
      "api-key": "2UxdSKWjuVxUJ6WconRae==RtKo=" //自己的api-key
    },
    method: "GET",
    success: function (e) {
      console.log("获取成功",e)
      that.setData({
        temp:e.data.data.datastreams[2].datapoints[0].value,
        humi:e.data.data.datastreams[1].datapoints[0].value,
        //cong:e.data.data.datastreams[4].datapoints[0].value,
        dagang:e.data.data.datastreams[0].datapoints[0].value
      })
      console.log("temp==",that.data.temp)
      console.log("humi==",that.data.humi)
      //console.log("cong==",that.data.cong)
      console.log("dagang==",that.data.dagang)
    }
   });
  },



switchChange: function(e){
 if (e.detail.value) {
   let data={
   "datastreams": [  
 {"id": "dagang","datapoints":[{"value": 1}]},
 //led是数据流的名称，value是要传上去的数值
     ]	
 }
  //按钮发送命令控制硬件
   wx.request({
     url:'https://api.heclouds.com/devices/1056036149/datapoints',
     header: {
       'content-type': 'application/json',
       'api-key':'CjFTVymYysBIY2Fa3X2wdXaPDKI='
     },
     method: 'POST',
     data: JSON.stringify(data),//data数据转换成JSON格式
     success(res){
       console.log("成功",res.data)
     },
     fail(res){
       console.log("失败",res)
     }
   })
 } else {
   console.log(0);
   let data={
     "datastreams": [  
   {"id": "dagang","datapoints":[{"value": 0}]},
   //led是数据流的名称，value是要传上去的数值
       ]	
   }
    //按钮发送命令控制硬件
     wx.request({
       url:'https://api.heclouds.com/devices/1056036149/datapoints',
       header: {
         'content-type': 'application/json',
         'api-key':'CjFTVymYysBIY2Fa3X2wdXaPDKI='
       },
       method: 'POST',
       data: JSON.stringify(data),//data数据转换成JSON格式
       success(res){
         console.log("成功",res.data)
       },
       fail(res){
         console.log("失败",res)
       }
     })
 }
},


   onLoad() {
     var that = this
     setInterval(function(){
      that.getinfo()
     },3000)
   
   }
})
