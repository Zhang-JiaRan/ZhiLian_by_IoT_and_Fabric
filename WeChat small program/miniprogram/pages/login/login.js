// miniprogram/pages/login/login.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    info:'Hello World',
    randomNum:Math.random()*10

  },
  login:function (e) {
    // wx:if(e.detail.value["username"]=="12345"&&e.detail.value["password"]=="12345")
    // {
    //   wx.switchTab({
    //     url: '/pages/main/main',
    //   })
    // }
    // e.detail.value["username"]=="12345"
    // e.detail.value["password"]=="12345"
    wx.switchTab({
      url: '/pages/main/main',
    })
    
  },

  btn4:function () {
    wx.switchTab({
      url: '/pages/sensor/sensor'
  })
  },

  goto_zhuce:function () {
    wx.navigateTo({
      url: '/pages/zci/zci',
    })
  },
  goto_update:function () {
    wx.navigateTo({
      url: '/pages/wji/wji'
  })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
      console.log(options)
      wx.getUserInfo({
        success:this.setUserInfo.bind(this),
      })
      this.setData({

      })
    },
      setUserInfo:function (res) {
        this.setData({
          user:res.userInfo
        })
        
      
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  },
  create_login: function (e) {
    console.log(e.detail.value)
    wx.request({
      url: "http://localhost:8080/WEB18/denglu?username=" + e.detail.value["username"] + "&" + "password=" + e.detail.value["password"] + "&phone=" + e.detail.value["phone"],
      //url地址为后端代码的位置需修改
      data: e.detail.value,
      success: this.getResult.bind(this)
    })
    
  },
  getResult: function (res) {
    console.log(res.data);
    if(res.data == "true"){
    wx.showToast({
      title: "登录成功",
      duration: 2000
    })
      wx.switchTab({
        url: '/pages/main/main'
      })
    setTimeout(function () {
      wx.navigateBack({
        delta: 2
      })
    }, 1000)
  }
  
  if(res.data == "false"){
    wx.showToast({
      title: "账号或密码不对",
      icon: 'none',
      duration: 3000
    })
    setTimeout(function () {
      wx.navigateBack({
        delta: 2
      })
    }, 1000)
  }
  },



})