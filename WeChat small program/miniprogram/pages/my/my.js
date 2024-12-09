// pages/personal/myinfo.ts
Page({
 
  /**
   * 页面的初始数据
   */
  data: {
 
  },
 
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad() {
 
    var that = this;
  },
 
  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {
 
  },
 
  // 退出登录
  logout: function () {
 
    wx.showModal({
      content: '确定退出登录吗？',
      cancelColor: '#666666',//666666
      confirmColor: '#666666',
      success(res) {
        if (res.confirm) {
          wx.reLaunch({
            url: '/pages/login/login'
          })
          console.log('用户点击确定')
        } else if (res.cancel) {
          console.log('用户点击取消')
        }
      },
      fail: function (res) { },//接口调用失败的回调函数
      complete: function (res) { },//接口调用结束的回调函数（调用成功、失败都会执行
    })
 
  },
  

  order:function () {
    wx.navigateTo({
      url: '/pages/mymain/order/order'
  })
  },
  message:function () {
    wx.navigateTo({
      url: '/pages/mymain/message/message'
  })
  },
  carhistory:function () {
    wx.navigateTo({
      url: '/pages/mymain/carhistory/carhistory'
  })
  },
  road:function () {
    wx.navigateTo({
      url: '/pages/mymain/road/road'
  })
  },
  peopleinfo:function () {
    wx.navigateTo({
      url: '/pages/mymain/peopleinfo/peopleinfo'
  })
  },
  password:function () {
    wx.navigateTo({
      url: '/pages/mymain/password/password'
  })
  },
  feedback:function () {
    wx.navigateTo({
      url: '/pages/mymain/feedback/feedback'
  })
  },


  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {
    wx.hideHomeButton();
    wx.hideShareMenu();
  },
 
  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {
 
  },
 
  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {
 
  },
 
  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {
 
  },
 
  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {
 
  },
 
  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {
 
  }
})