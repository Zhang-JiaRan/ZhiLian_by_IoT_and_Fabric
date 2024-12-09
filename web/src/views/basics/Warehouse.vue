<!-- <template>
  <div class="container">
      <div id="map-container">地图</div>
  </div>
</template>

<script>
export default {
name: '',
components: {},
data () {
  return {
    map: null,
    markers: [],
    markersPosition: [],
    geoCoder: null
  }
},
mounted () {
  this.mapInit()
},
methods: {
  mapInit () {
    // eslint-disable-next-line no-undef
    this.map = new AMap.Map('map-container', {
      zoom: 11, // 级别
      // center: [116.397428, 39.90923], // 中心点坐标
      // layers: [ // 使用多个图层
      //   // 卫星
      //   new AMap.TileLayer.Satellite(),
      //   // 路网
      //   new AMap.TileLayer.RoadNet()
      // ],
      resizeEnable: true
      // viewMode: '3D'// 使用3D视图
    })

    // eslint-disable-next-line no-undef
    this.geoCoder = new AMap.Geocoder()

    this.handlerMapClick()
  },
  handlerMapClick () {
    this.map.on('click', (e) => {
      // 点击坐标
      this.markersPosition = [e.lnglat.lng, e.lnglat.lat]

      this.removeMarker()
      // 设置新的标记
      this.setMapMarker()

      // eslint-disable-next-line no-undef
      // 根据坐标获取位置信息
      this.geoCoder.getAddress(this.markersPosition, (status, result) => {
        if (status === 'complete' && result.regeocode) {
          this.address = result.regeocode.formattedAddress
          console.log('点击位置信息：', result.regeocode.formattedAddress)
          // id
          let adcode = result.regeocode.addressComponent.adcode
          //   let reg = /.+?(省|市|自治区|自治州|县|区)/g
          let provinceId = parseInt(adcode.substr(0, 2) + '0000')
          let cityId = parseInt(adcode.substr(0, 4) + '00')
          let areaId = adcode
          console.log('点击位置的省市区id：', provinceId, cityId, areaId)
        }
      })
    })
  },
  // 设置点击位置的标记
  setMapMarker () {
    let marker = new AMap.Marker({
      map: this.map,
      position: this.markersPosition
    })
    // 将 markers 添加到地图
    this.markers.push(marker)
  },
  // 添加标记
  addMarker () {
    //   经度 纬度
    let lng = Math.random() * 135.05 + 73.3
    let lat = Math.random() * 53.33 + 3.51
    console.log('添加标记', [lng, lat])
    // 添加标记
    this.map.setFitView()

    let marker = new AMap.Marker({
      map: this.map,
      position: [lng, lat]
      // content: markerContent
      // eslint-disable-next-line
              // offset: new AMap.Pixel(-13, -30)
    })
    // 将 markers 添加到地图
    this.markers.push(marker)

    this.map.setFitView()`在这里插入代码片`

    // 鼠标点击marker弹出自定义的信息窗体
    // eslint-disable-next-line no-undef
    AMap.event.addListener(marker, 'click', function (e) {
      console.log('点击marker', e)
    })
  },
  // 删除之前后的标记点
  removeMarker () {
    if (this.markers) {
      this.map.remove(this.markers)
    }
  }
}
}
</script>

<style scoped lang="scss">
#map-container {
  width: 70vw;
  height: 70vh;
}
</style> -->