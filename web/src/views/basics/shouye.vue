<template>
  <div>
    <div>
      <a-spin size="large" :spinning="spinning">
        <a-card style="border: 0px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" class="shouye">

          <a-row :gutter="20">
            <a-col :span="6" class="item">
              <a-card hoverable class="add-item" @click="visible = true"
                style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
                <a-row>

                  <img src="https://img.51miz.com/Element/00/37/93/24/6a06b5d2_E379324_4dc7d1a3.png" alt=""
                    class="img1" />
                </a-row>
                <a-row>
                  <p class="name">管理员</p>
                  <p class="name1">管理员ID:<span>123456</span></p>
                  <p class="name2">管理员权限：<span>所有</span></p>
                </a-row>

                <!-- <div class="login-info">
                  <p class="name1">管理员ID:<span>123456</span></p>
                  <p class="name2">管理员权限：<span>所有</span></p>
                </div> -->
              </a-card>
            </a-col>

            <a-col :span="6" class="item">
              <a-card hoverable class="add-item1" @click="visible = true"
                style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
                <a-row :gutter="16" align="middle">
                  <a-col :span="6">
                    <img src="../../assets/driver.png" alt="" class="img3">
                  </a-col>
                  <a-col :span="18">
                    <a-row :gutter="30">
                      <p style="margin-top:20px; margin-left: 55px; font-size: medium;font-weight:400;">在线司机数</p>
                    </a-row>
                    <a-row :gutter="30">
                      <p style="margin-left: 50px; font-size: xx-large;font-weight:400;font-style: italic;">15/32</p>
                    </a-row>
                  </a-col>
                </a-row>
                <!-- <div class="login-info">
                <p class="name4">在线/总数</p>
              </div> -->
              </a-card>
              <a-card hoverable class="add-item2" @click="visible = true"
                style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
                <a-row :gutter="16" align="middle">
                  <a-col :span="6">
                    <img src="../../assets/truck.png" alt="" class="img2">
                  </a-col>
                  <a-col :span="18">
                    <a-row :gutter="30">
                      <p style="margin-top:20px; margin-left: 20px; font-size: medium;font-weight:400; ">在线货车数</p>
                    </a-row>
                    <a-row :gutter="30">
                      <p style="margin-left: 15px; font-size: xx-large;font-weight:400;font-style: italic;">4/10</p>
                    </a-row>
                  </a-col>
                </a-row>
                <!-- <div class="login-info">
                <p class="name4">在线/总数</p>
              </div> -->

              </a-card>
            </a-col>

            <a-col :span="12" class="item">
              <a-card hover @click="visible = true" class="message" :bordered="true" :bodyStyle="{ paddingTop: '12px', }"
                style="height:370px ">
                <template>
                  <h6 style="font-size: large;">事项速办</h6>
                  <p style="color:black;font-size: small;margin-top: 5px;margin-bottom: 15px;">最新通知 <span
                      class="text-success"></span></p>
                </template>
                <a-timeline :reverse="timelineReverse" mode="left">
                  <a-timeline-item :color="processcolor" @click="process = true" class="line1">
                    <p style="color:black">反馈：李四 </p>
                    <p style="color:black">反馈内容：行驶中，疲劳提醒功能无法使用。</p>
                    <p style="color:grey; font-style: italic;">四月六号 下午三点五十</p>
                  </a-timeline-item>
                  <a-timeline-item color="green">
                    <p style="color:black">通知：更新司机 </p>
                    <p style="color:black">通知内容：最新三位司机可以上岗工作</p>
                    <p style="color:grey; font-style: italic;">四月六号 下上午九点</p>
                  </a-timeline-item>
                  <a-timeline-item color="green">
                    <p style="color:black">反馈：朱三 </p>
                    <p style="color:black">反馈内容：刷卡失败，需要补办。</p>
                    <p style="color:grey; font-style: italic;">四月三号 下午三点五十</p>
                  </a-timeline-item>
                  <a-timeline-item color="green">
                    <p style="color:black">通知：系统更新 </p>
                    <p style="color:black">通知内容：路径优化出现卡死的漏洞已修复。</p>
                    <p style="color:grey; font-style: italic;">四月一号 下午六点五十</p>
                  </a-timeline-item>
                  <template #pendingDot> </template>
                </a-timeline>
                <router-link to="/delivery/fankuichuli">
                  <a-tooltip title="快速跳转">
                    <a-button key="console" type="link" shape="circle">
                      更多记录
                    </a-button>
                  </a-tooltip>
                </router-link>
              </a-card>
              <!-- <a-card hoverable class="add-item" @click="visible = true" style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);
                border-radius: 30px;">
              <div>
                <img src="../../assets/truck.png" alt="" class="img2">
                <div>
                  <p class="name3">600/666</p>
                </div>
              </div>
              <div class="login-info">
                <p class="name4">在线/总数</p>
              </div>
            </a-card> -->
            </a-col>

            <a-col :span="24" class="item">
              <a-card class="add-2" style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1); border-radius: 30px;">
                <a-col :span="12">
                  <div id="main" style="height:300px;"></div>
                </a-col>
                <a-col :span="12">
                  <div id="main1" style="height:300px;"></div>
                </a-col>
              </a-card>
            </a-col>
            <a-col :span="24" class="item">
              <a-card hoverable class="mymap" @click="visible = true"
                style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
                <div class="add-map" style="margin-top: 0px;">
                  <Mapview style="border-radius: 30px; border: 1px dashed; height: 400px;" />
                </div>
                <div>
                  <p style="margin-top: 420px;font-size: large;font-weight:1000; text-align: center;">货车分布图</p>
                </div>
              </a-card>
            </a-col>
          </a-row>
        </a-card>
      </a-spin>
    </div>
    <div>
      <a-modal title="事项信息" :visible="process" @ok="process = false, processcolor = 'green'" @cancel="process = false"
        style="border-radius: 100px; ">
        <a-form-model :model="form" style="height:300px">
          <a-form-model-item label="反馈内容">
            <a-card hoverable @click="visible = true" style="border-radius: 10px;">
              <a-row>
                司机：王师傅
              </a-row>
              <a-row>
                反馈内容：刷卡失败，需要补办。
              </a-row>
            </a-card>
          </a-form-model-item>

          <a-form-model-item label="处理反馈" style="border-radius: 50px; height: 70px;">
            <a-input v-model="form.address" type="textarea" style="height:150px" />
          </a-form-model-item>
        </a-form-model>
      </a-modal>
    </div>
  </div>
</template>
<script>
import { FindAllVehicle, SaveVehicle } from "@/api/vehicle";
import * as echarts from 'echarts';
import Mapview from "../../components/Mapview.vue";
export default {
  name: "WareHouse",
  components: {
    Mapview,
  },
  data() {
    return {
      processcolor: "red",
      process: false,
      timelineReverse: false,
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
      let myChart1 = this.$echarts.init(document.getElementById("main"));
      let myChart2 = this.$echarts.init(document.getElementById("main1"));
      // 指定图表的配置项和数据
      let option1 = {
        tooltip: {
          trigger: 'item'
        },
        legend: {
          top: '5%',
          bottom: '0%',
          left: 'center'
        },
        series: [
          {
            name: '',
            type: 'pie',
            radius: ['40%', '70%'],
            avoidLabelOverlap: false,
            itemStyle: {
              borderRadius: 10,
              borderColor: '#fff',
              borderWidth: 2
            },
            label: {
              show: false,
              position: 'center'
            },
            emphasis: {
              label: {
                show: true,
                fontSize: 15,
                fontWeight: 'bold'
              }
            },
            labelLine: {
              show: false
            },
            data: [
              { value: 1900, name: '冷藏食品', itemStyle: { color: '#5EC684' } },
              { value: 735, name: '花卉植物', itemStyle: { color: '#E57B7B' } },
              { value: 580, name: '化学医药', itemStyle: { color: '#41ADEB' } },
            ]
          }
        ],
        grid: {
          containLabel: true,
          top: '80%'
        },
        graphic: {
          elements: [{
            type: 'text',
            z: 100,
            left: 'center',
            top: '94%',
            style: {
              fill: '#666',
              text: '本月运输物品类目明细统计表/单         ',
              font: 'bold 16px Arial'
            }
          }]
        }
      };
      let option2 = {
        legend: {},
        tooltip: {},
        dataset: {
          dimensions: ['product', '冷藏食品', '花卉植物', '化学医药'],
          source: [
            { product: '第一季度', 冷藏食品: 6330, 花卉植物: 8580, 化学医药: 9370 },
            { product: '第二季度', 冷藏食品: 8310, 花卉植物: 7340, 化学医药: 5510 },
            { product: '第三季度', 冷藏食品: 8640, 花卉植物: 6520, 化学医药: 8250 },
            { product: '第四季度', 冷藏食品: 7240, 花卉植物: 5390, 化学医药: 3910 }
          ]
        },
        xAxis: { type: 'category' },
        yAxis: {
          axisLabel: {
            formatter: function (value, index) {
              return parseInt(value / 1000) + 'k'; //将数值除以1000，再加上"k"单位
            }
          }
        },
        // Declare several bar series, each will be mapped
        // to a column of dataset.source by default.
        series: [
          {
            type: 'bar',
            itemStyle: {
              color: '#C5A0C7' // 将第一系列的颜色设置为红色
            }
          },
          {
            type: 'bar',
            itemStyle: {
              color: '#6EB5D0' // 将第二系列的颜色设置为蓝色
            }
          },
          {
            type: 'bar',
            itemStyle: {
              color: '#F59432' // 将第三系列的颜色设置为绿色
            }
          }
        ],
        grid: {
          top: '20%' // 将 top 属性值设为 20% ，即向下移动了 20% 的距离
        },
        graphic: {
          elements: [{
            type: 'text',
            z: 10000,
            left: 'center',
            top: '94%',
            style: {
              fill: '#666',
              text: '运输物品季度变化/单',
              font: 'bold 16px Arial'
            }
          }]
        }
      };

      option1 && myChart1.setOption(option1);
      option2 && myChart2.setOption(option2);
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

.add-1 {
  text-align: center;
  line-height: 200px;
  min-height: 200px;
  /* border: 1px dashed #91949c; */
  border-radius: 5%;
}

.add-2 {
  text-align: center;
  line-height: 300px;
  min-height: 300px;
  /* border: 1px dashed #91949c; */
  border-radius: 1%;
}

.add-2:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}

.add-3 {
  text-align: center;
  height: 350px;
  /* border: 1px dashed #91949c; */
  border-radius: 1%;
}

.add-4 {
  text-align: center;
  height: 300px;
  /* border: 1px dashed #91949c; */
  border-radius: 1%;
}

.add-item {
  text-align: center;
  line-height: 15px;
  height: 370px;
  /* border: 1px dashed #91949c; */
  border-radius: 5%;

}

.add-item:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}

.item {
  margin-bottom: 20px;
  border-radius: 5%;
}

.add-item1 {
  text-align: left;
  line-height: 40px;
  height: 175px;
  /* border: 1px dashed #91949c; */
  border-radius: 5%;
}

.add-item1:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}

.add-item2 {
  margin-top: 20px;
  text-align: center;
  line-height: 40px;
  height: 175px;
  /* border: 1px dashed #91949c; */
  border-radius: 5%;
}

.add-item2:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}


.image {
  width: 80px;
  height: 80px;
  margin-left: 20px;
}

.user {
  padding-bottom: 20px;
  display: flex;
  align-items: center;
  margin: 0;
  padding: 0;
}

.name {
  font-size: 20px;
  margin-top: 10px;
  font-weight: ;
}

.name1 {
  font-size: 15px;
  margin-top: 30px;

}

.name2 {
  font-size: 14px;
  margin-top: 30px;
}

.name3 {
  font-size: 20px;
  margin-left: 100px;
  margin-bottom: 600px;
  /* margin-top: 30px; */
}

.name4 {
  font-size: 15px;
  margin-top: 60px;
}

.access {
  color: #999999;
}

.img1 {
  /* margin-right: 40px; */
  width: 170px;
  height: 170px;
  border-radius: 50%;
}

.img2 {
  /* margin-right: 40px; */
  margin-top: 25px;
  margin-right: 100px;
  width: 85px;
  height: 70px;
}

.img3 {
  /* margin-right: 40px; */
  margin-top: 25px;
  margin-right: 150px;
  width: 65px;
  height: 65px;
}

.login-info {
  line-height: 10px;
  font-size: 14px;
  color: #999999;
}

.login-info:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}

.message {
  /* border: 1px dashed #91949c; */
  box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);
}

.message:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}

.mymap {
  text-align: center;
  height: 500px;
  line-height: 30px;
  min-height: 300px;
  /* border: 1px dashed #91949c; */
  border-radius: 1%;
}

.mymap:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}
</style>
