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
                    zoom: 6, // 当前缩放级别
                    zooms: [2, 22], // 缩放级别范围
                    center: [118.3564, 36.1046], // 中心点
                });
                var markerList = [marker1, marker2, marker3, marker4, marker5, marker6, marker7, marker8, marker9, marker10];
                var marker1 = new AMap.Marker({
                    position: new AMap.LngLat(120.18, 35.94),
                    title: '青岛市-黄岛区'
                });

                var marker2 = new AMap.Marker({
                    position: new AMap.LngLat(116.737598, 36.106108),
                    title: '泰安市-肥城市'
                });

                var marker3 = new AMap.Marker({
                    position: new AMap.LngLat(117.127886, 36.114027),
                    title: '济宁市-曲阜市'
                });

                var marker4 = new AMap.Marker({
                    position: new AMap.LngLat(118.0605, 34.7065),
                    title: '临沂市-兰陵县'
                });

                var marker5 = new AMap.Marker({
                    position: new AMap.LngLat(116.4533, 37.1147),
                    title: '德州市-平原县'
                });

                var marker6 = new AMap.Marker({
                    position: new AMap.LngLat(115.9125, 34.7875),
                    title: '菏泽市-成武县'
                });

                var marker7 = new AMap.Marker({
                    position: new AMap.LngLat(116.4841, 35.7214),
                    title: '济宁市-汶上县'
                });

                var marker8 = new AMap.Marker({
                    position: new AMap.LngLat(115.1578, 35.2722),
                    title: '菏泽市-东明县'
                });

                var marker9 = new AMap.Marker({
                    position: new AMap.LngLat(115.7647, 36.8279),
                    title: '聊城市-临清市'
                });

                var marker10 = new AMap.Marker({
                    position: new AMap.LngLat(115.6499, 35.0930),
                    title: '菏泽市-定陶县'
                });


                var markerList = [marker1, marker2, marker3, marker4, marker5, marker6, marker7, marker8, marker9, marker10];
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