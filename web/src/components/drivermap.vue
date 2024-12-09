<template>
    <div id="container" class='add-map'>
    </div>
</template>
<script>
import AMapLoader from '@amap/amap-jsapi-loader';

export default {
    name: "drivermap",
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
                plugins: ['AMap.ToolBar', 'AMap.Driving', 'AMap.Marker'], // 插件
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
                    zoom: 13, // 当前缩放级别
                    zooms: [2, 22], // 缩放级别范围
                    center: [120.17, 35.95], // 中心点
                });
                var markerList = [marker1];
                var marker1 = new AMap.Marker({
                    position: new AMap.LngLat(120.17, 35.95),
                    title: '青岛市-黄岛区-江山瑞城'
                });

                var markerList = [marker1];
                this.map.add(markerList);
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
     margin: 0px;
     width: 95%;
     height: 90%;
     position: absolute;
 }
</style> 