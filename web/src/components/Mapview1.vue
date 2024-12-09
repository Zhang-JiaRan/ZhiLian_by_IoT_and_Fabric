<template>
    <div id="container" class='add-map'>
    </div>
</template>
<script>
import AMapLoader from '@amap/amap-jsapi-loader';

export default {
    name: "Mapview",
    data() {
        return {
            map: null,
        }
    },
    created() {

    },
    mounted() {
        this.initAMap();


    },
    methods: {
        initAMap() {
            AMapLoader.load({
                key: 'ca35d97d523da22c8d8082744956d137',  //设置您的key
                version: "2.0", // 高德地图版本
                plugins: ['AMap.ToolBar','AMap.Driving'], // 插件
                AMapUI: { // 高德地图UI组件库，可不写，内部提供了覆盖物标注点，以及部分模块的封装
                    version: "1.1",
                    plugins: [],
                },
                Loca: { // Loca版本(高性能地图数据可视化库) 可不写
                    version: "2.0"
                },

            }).then((AMap) => {
                // container渲染的id
                this.map = new AMap.Map("container", {
                    zoom: 5, // 当前缩放级别
                    zooms: [2, 22], // 缩放级别范围
                    center: [105.602725, 37.076636], // 中心点
                });
                var driving = new AMap.Driving({
                    // 驾车路线规划策略，AMap.DrivingPolicy.LEAST_TIME是最快捷模式
                    policy: AMap.DrivingPolicy.LEAST_TIME,
                    map: this.map,
                    panel: "panel"
                })


                driving.search(new AMap.LngLat(112.549,37.857), new AMap.LngLat(116.39, 39.9), function (status, result) {
                    // result 即是对应的驾车导航信息，相关数据结构文档请参考  https://lbs.amap.com/api/javascript-api/reference/route-search#m_DrivingResult
                    if (status === 'complete') {
                        log.success('绘制驾车路线完成')
                    } else {
                        log.error('获取驾车数据失败：' + result)
                    }
                });

            }).catch(e => {
                console.log(e);
            })
        },

    }
} </script>
<style  scoped> .home_div {
     padding: 0px;
     margin: 0px;
     width: 100%;
     height: 100%;
     position: relative;
 }

 #container {
     padding: 0px;
     margin-top: 30px;
     width: 95%;
     height: 80%;
     position: absolute;
 }
</style>