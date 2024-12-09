<template>
  <div>
    <a-spin size="large" :spinning="spinning">
      <a-row :gutter="20">
        <a-col :span="24" class="item">
          <a-card hoverable class="add-item" @click="visible = true">
            <div>
              <a-col :span="24">
                <div id="main" style="height:300px;"></div>
              </a-col>
            </div>
          </a-card>
        </a-col>
      </a-row>
    </a-spin>
  </div>
</template>
<script>
import { FindAllVehicle, SaveVehicle } from "@/api/vehicle";
import * as echarts from 'echarts';
import Mapview1 from "../../components/Mapview1.vue";
export default {
  name: "WareHouse",
  components: {
    Mapview1
  },
  data() {
    return {
      visible: false,
      spinning: false,
      form: {
        number: '京A0000',
        type: '快递',
        driving: false,
      },
      data: [],
      imgList: [
        require('../../assets/warehouse0.svg'),
        require('../../assets/warehouse1.svg'),
        require('../../assets/warehouse2.svg'),]
    }
  },
  mounted() {
    this.loadData()
  },
  methods: {
    drawChart() {
      // 基于准备好的dom，初始化echarts实例
      let myChart = this.$echarts.init(document.getElementById("main"));
      // 指定图表的配置项和数据
      let option = {

        title: {
          text: '碳排放记录',
          x: 'center'
        },

        legend: { // 图例配置选项
          orient: 'horizontal', //图例布局方式：水平 'horizontal' 、垂直 'vertical'
          x: 'left', // 横向放置位置，选项：'center'、'left'、'right'、'number'（横向值 px）
          y: 'top',// 纵向放置位置，选项：'top'、'bottom'、'center'、'number'（纵向值 px）
          data: ['上月', '本月']
        },
        grid: {  // 图表距离边框的距离，可用百分比和数字（px）配置
          top: '20%',
          left: '3%',
          right: '10%',
          bottom: '5%',
          containLabel: true
        },

        xAxis: {
          name: '日期',
          type: 'category',
          data: ['4.02', '4.03', '4.04', '4.05', '4.06', '4.07', '4.08', '4.09', '4.10', '4.11', '4.12', '4.13',]
        },

        yAxis: {
          name: '碳排放量/kg',
          type: 'value',
          min: 0, // 配置 Y 轴刻度最小值
          max: 4000,  // 配置 Y 轴刻度最大值
          splitNumber: 7,  // 配置 Y 轴数值间隔
        },

        series: [
          

          {
            name: '上月',
            data: [2455, 2534, 2360, 2301, 2861, 2181, 1944, 2197, 1745, 1810, 2283, 2298],
            type: 'line',
            symbolSize: 8,  //设置折线上圆点大小
            itemStyle: {
              normal: {
                label: {
                  show: true // 在折线拐点上显示数据
                },
                lineStyle: {
                  width: 3,  // 设置虚线宽度
                  type: 'dotted'  // 虚线'dotted' 实线'solid'
                }
              }
            }
          },

          {
            name: '本月',
            data: [1107, 1352, 1740, 1968, 1647, 1570, 1343, 1757, 2547, 2762, 3170, 3665],
            type: 'line',
            symbol: 'circle', // 实心圆点
            smooth: 0.5, // 设置折线弧度
            symbolSize: 8,  //设置折线上圆点大小
            itemStyle: {
              normal: {
                label: {
                  show: true // 在折线拐点上显示数据
                },
                lineStyle: {
                  width: 3,  // 设置虚线宽度
                  type: 'dotted'  // 虚线'dotted' 实线'solid'
                }
              }
            }
          }
        ],
        color: ['#3366CC', '#FFCC99', '#99CC33'] // 三个折线的颜色
      }
      option && myChart.setOption(option);
      // 指定图表的配置项和数据
    }
  },
  mounted() {
    this.drawChart();
  },
}
</script>
<style scoped>
* {
  margin: 0;
  padding: 0;
}

.add-item {
  text-align: center;
  line-height: 30px;
  height: 600px;
  border: 1px dashed #91949c;
  border-radius: 2%;
}

.add-item:hover {
  border: 1px dashed #5a84fd;
  color: #5a84fd;
}

.item {
  margin-bottom: 20px;
  border-radius: 1%;
}

.user {
  padding-bottom: 20px;
  display: flex;
  align-items: center;
  margin: 0;
  padding: 0;
}

.ziti-1 {
  font-size: 30px;
  ;
  margin-left: 0px;
}</style>