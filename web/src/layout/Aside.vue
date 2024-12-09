<template>
  <a-layout-sider :style="{ overflow: 'auto', height: '100vh', position: 'fixed', left: 0 }" width="230">
    <div class="logo">
      <img src="../assets/aside.svg" alt="" >
      物流管理系统
    </div>
    <a-menu theme="light" mode="inline">
      <a-menu-item v-for="menu in menus" :key="menu.title">
        <router-link :to="menu.path">
          <a-icon :type="menu.icon" />
          {{ menu.title }}
        </router-link>
      </a-menu-item>
    </a-menu>
  </a-layout-sider>
</template>
<script>

import path from 'path';
import { title } from 'process';
export default {
  data() {
    return {
      menus: [
        { title: '首页', icon: 'home', path: '/shouye' },
        { title: '驾驶员信息', icon: 'user', path: '/driver' },
        { title: '货车信息', icon: 'car', path: '/vehicle' },
        { title: '实时监控', icon: 'environment', path: '/tracking' },
        { title: '路径规划', icon: 'fork', path: '/lujingguihua' },
        { title: '申请配送', icon: 'shopping', path: '/delivery/create' },
        { title: '配送列表', icon: 'bars', path: '/delivery/list' },
        { title: '可追溯', icon: 'interaction', path: '/delivery/KEZHUISU' },
        { title: '反馈处理', icon: 'carry-out', path: '/delivery/fankuichuli' },
        { title: '碳排放', icon: 'line-chart', path: '/tanpaifang' },
        { title: '', path: '' },
        { title: '', path: '' },
        { title: '', path: '' },
        { title: '', path: '' },
        { title: '', path: '' },
        { title: '', path: '' },
        { title: '', path: '' },
        // { title: '入库分析', path: '/analyze/in' },
        // { title: '出库分析', path: '/analyze/out' },
        // { title: '安全设置', path: '/security' },
        // { title: '操作员管理', path: '/admin' },
        // { title: '权限列表', path: '/role' },
        // { title: '来往单位', icon: 'shopping', path: '/company' },
        // { title: '仓库管理', icon: 'shopping', path: '/warehouse' },
        // { title: '销售开票', icon: 'shopping', path: '/sale/create' },
        // { title: '销售记录', icon: 'shopping', path: '/sale/record' },

        //{title: '销售记录', path: '/sale/record'},
        // {
        //   title: '员工管理',icon:'shopping',path: '/employee'
        // },
        // {
        //   title: '动态监测', icon:'shopping',path: '/employee'
        // },
        // {
        //   title: '路径优化', icon:'shopping',path: '/company'
        // },
        // {
        //   title: '货车分布地图', icon:'shopping',path:'/warehouse'
        // },
        // {
        //   title: '反馈', icon:'shopping',path:'/warehouse'
        // },
        // {
        //   title: '可追溯', icon:'shopping',path:'/delivery/list'
        // },
      ]
      //         {
      //           title: '基础信息管理',
      //           icon: 'home',
      //           children: [
      //             {title: '商品管理', path: '/commodity'},
      //             {title: '来往单位', path: '/company'},
      //             {title: '员工管理', path: '/employee'},
      //             {title: '仓库管理', path: '/warehouse'},
      //           ]
      //         },
      //         {
      //           title: '销售信息管理',
      //           icon: 'pay-circle',
      //           children: [
      //             {title: '销售开票', path: '/sale/create'},
      //             {title: '销售记录', path: '/sale/record'},
      //           ]
      //         },
      //         {
      //           title: '配送信息管理',
      //           icon: 'car',
      //           children: [
      //             {title: '申请配送', path: '/delivery/create'},
      //             {title: '配送列表', path: '/delivery/list'},
      //           ]
      //         },
      //         {
      //           title: '运输信息管理',
      //           icon: 'rocket',
      //           children: [
      //             {title: '车辆资料', path: '/vehicle'},
      //             {title: '驾驶员资料', path: '/driver'},
      //           ]
      //         },
      //         {
      //           title: '系统决策管理',
      //           icon: 'line-chart',
      //           children: [
      //             {title: '入库分析', path: '/analyze/in'},
      //             {title: '出库分析', path: '/analyze/out'},
      //           ]
      //         },

      //        {
      //           title: '系统信息管理',
      //           icon: 'tool',
      //           children: [
      //             {title: '安全设置', path: '/security'},
      //             {title: '操作员管理', path: '/admin'},
      //             {title: '权限列表', path: '/role'},
      //           ]
      //         },
      //       ]
      //     }  
      // },
    }
  },
}
</script>

<style scoped>
#components-layout-demo-fixed-sider .logo {
  /* padding: 10px 15px; */
  height: 80px;
  font-size: 15px;
  text-align: center;
  padding-top: 15%;
  padding-left: 0%;
  padding-right: 10%;
  /* margin: 16px; */
  color: #050000;
  /* letter-spacing: 2px; */
  background-color: #ffffff;

}

.ant-menu {
  letter-spacing: 1px;
}

.logo img {
  width: 45px;
  height: 45px;
  margin-right: 20px;
}
</style>