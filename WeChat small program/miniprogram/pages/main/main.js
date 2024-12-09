Page({

  /**
   * 页面的初始数据
   */
  data: {
    total_days:'134',
  },
  main1:function () {
    wx.navigateTo({
      url: '/pages/weather/weather'
  })
  },
  main2:function () {
    wx.switchTab({
      url: '/pages/sensor/sensor'
  })
  },
  main3:function () {
    wx.navigateTo({
      url: '/pages/mapmore/mapmore'
  })
  },
  main4:function () {
    wx.switchTab({
      url: '/pages/maproute/maproute'
  })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
  }

})
