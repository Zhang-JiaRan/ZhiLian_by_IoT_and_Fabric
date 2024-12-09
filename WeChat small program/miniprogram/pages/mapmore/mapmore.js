Page({
  data: {
    longitude: 120.17956, //地图界面中心的经度
    latitude: 35.94423, //地图界面中心的纬度
    markers: [ //标志点的位置
      //位置0
      {
        id: 0,
        iconPath: "/images/标记点.svg",
        latitude: 35.94423,
        longitude: 120.17956,
        width: 28,
        height: 32
      },
      //位置1
      {
        id: 1,
        iconPath: "/images/标记点.svg",
        latitude: 35.06262,
        longitude: 118.53108,
        width: 28,
        height: 32
      },
      // //位置2
      // {
      //   id: 2,
      //   iconPath: "/images/here.png",
      //   latitude: 23.02542516569787,
      //   longitude: 113.1417505798413,
      //   width: 28,
      //   height: 32
      // },
 
    ]
  },

  onLoad: function () {
    var that = this;

    wx.getLocation({
      type: "wgs84",
      success: function (res) {
        var latitude = res.latitude;
        var longitude = res.longitude;
        console.log("当前位置的经纬度为：", res.latitude, res.longitude);
        that.setData({
          latitude: res.latitude,
          longitude: res.longitude,

        })
      }
    })
  },
  onReady: function () {

  },

  /**
   * 地图放大缩小事件触发
   * @param {*} e 
   */
  bindregionchange(e) {
    console.log('=bindregiοnchange=', e)
  },

  /**
   * 点击地图事件，有经纬度信息返回
   * @param {*} e 
   */
  bindtapMap(e) {
    console.log('=bindtapMap=', e)
  }
})
