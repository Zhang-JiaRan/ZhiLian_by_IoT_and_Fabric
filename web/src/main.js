import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import Antd from 'ant-design-vue'
import 'ant-design-vue/dist/antd.css'
import JsonExcel from 'vue-json-excel'
import * as echarts from 'echarts';
import './assets/font/hanyi.css';

Vue.prototype.$echarts = echarts

Vue.component('downloadExcel', JsonExcel)

Vue.config.productionTip = false

Vue.use(Antd);

import BaiduMap from 'vue-baidu-map'
Vue.use(BaiduMap, { ak: 'NwvYlmeIgBYXX3sADSHn0octSIMWqTDB' })

window._AMapSecurityConfig = {
  securityJsCode: '35a5c10c54d70e358bb64254936b388a' // 输入你的jscode
}


new Vue({
  router,
  store,
  render: function (h) { return h(App) }
}).$mount('#app')
