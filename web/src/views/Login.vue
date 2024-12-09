<template>
  <div class="backcolor">
    <div class="login-box">
      <div class="main">
        <div class="box-header">
          <!-- <img class="logo" src="../assets/logo.svg" alt=""/> -->
          <div class="box-header-t">智达管理平台</div>
        </div>
        <!-- <div class="title">Logistics Management 冷链运输管理系统 - 管理员登录</div> -->
        <a-tabs size="middle" @change="tabClick" default-active-key="1" :tabBarStyle="{ textAlign: 'center' }">
          <a-tab-pane key="1" tab="密码登陆" size='large'>
            <a-input v-model="form.email" size="middle" style="margin-top: 10px" class="input" placeholder="邮箱">
              <a-icon slot="prefix" type="mail" style="padding: 0 5px" />
            </a-input>
            <a-input-password v-model="form.password" size="middle" class="input" placeholder="密码">
              <a-icon slot="prefix" type="lock" style="padding: 0 5px" />
            </a-input-password>
          </a-tab-pane>
          <a-tab-pane key="2" tab="验证码登陆" force-render>
            <a-input v-model="form.email" size="middle" style="margin-top: 10px" class="input" placeholder="邮箱">
              <a-icon slot="prefix" type="mail" />
            </a-input>
            <div style="display: flex">
              <a-input v-model="form.code" size="middle" class="input" placeholder="验证码">
                <a-icon slot="prefix" type="safety-certificate" />
              </a-input>
              <a-button class="code-btn" size="small" :loading="sendLoading" @click="sendEmail">
                获取验证码
              </a-button>
            </div>
          </a-tab-pane>
        </a-tabs>
        <div style="margin-bottom: 20px">
          <a-checkbox v-model="form.remember" style="font-size: small; padding: 0 10px">自动登录</a-checkbox>
          <a-button type="link" style="margin-left: 93px; font-size: small;">
            忘记密码 ?
          </a-button>
        </div>
        <a-button :loading="submitLoading" class="submit-btn" type="primary" @click="submitLogin">
          确认登陆
        </a-button>
      </div>
    </div>
  </div>
</template>

<script>
import { AdminLogin, AdminSendEmail } from "@/api/admin";
import { IsInit } from "../api/admin";

export default {

  data() {
    return {
      sendLoading: false,
      submitType: '1', //1账号登录 2邮箱登录
      submitLoading: false,
      form: {
        password: '',
        email: '',
        code: '',
        remember: false,
      },
    }
  },

  mounted() {
    IsInit().then((res) => {
      if (!res.status) this.$router.push('/init')
    })
  },

  methods: {

    sendEmail() {
      if (this.checkEmail()) {
        this.sendLoading = true
        AdminSendEmail(this.form.email).then((res) => {
          if (res.status) this.$message.success("验证码发送成功")
          this.sendLoading = false
        })
      }
    },

    submitLogin() {
      if (this.checkEmail()) {
        let type = this.submitType === '1' ? "passwrod" : "email"
        AdminLogin(type, this.form).then((res) => {
          console.log(res.data)
          if (res.status) {
            this.$store.commit('user/saveToken', res.data.token)
            console.log(res.data.token)
            console.log('i have a dream')
            console.log(res.data.admin)
            this.$store.commit('user/saveLoginUser', res.data.admin)
            setTimeout(() => {
              this.$router.push("/shouye")
              this.submitLoading = false
            }, 700)
            this.$message.success("登陆成功")
          }
        })
      }
    },

    tabClick(key) {
      this.submitType = key
    },


    checkEmail() {
      const emailRegex = new RegExp('^\\w{3,}(\\.\\w+)*@[A-z0-9]+(\\.[A-z]{2,5}){1,2}$')
      if (!emailRegex.test(this.form.email)) {
        this.$message.error('请输入正确格式的邮箱');
        return false
      } else {
        return true
      }
    },

  },
  

}
</script>

<style scoped>

body{
  background-color: black;
}

.ant-tabs-bar {
  border-bottom: none !important;
}

.ant-btn-primary {
  border-color: #5a84fd;
}

.login-box {
  box-shadow: 0 3px 8px 0;
  border-radius: 30px;
  width: 800px;
  height: 400px;
  position: absolute;
  left: 50%;
  top: 50%;
  transform: translate(-50%, -50%);
  background-image: url(../assets/zhuye-background.png);
  background-size: 100%;
}

.box-header {
  display: flex;
}

.box-header-t {
  font-weight: bolder;
  font-size: 35px;
  margin-top: 40px;
  margin-left: 50px;
  font-family:fantasy;
}

.logo {
  width: 44px;
  height: 44px;
  margin-right: 20px;
  margin-left: 43px;
}

.ant-tabs-nav {
  width: 350px;
}

.ant-tabs-ink-bar {
  left: 52px;
}

.ant-input-affix-wrapper .ant-input {
  font-size: 12px !important;
}

.title {
  color: #91949c;
  padding-top: 15px;
  padding-bottom: 35px;
  font-size: 13px;
  text-align: center;
}

.input {
  margin-bottom: 25px;
  font-size: 10px;
  font-family: 'hanyi';
  padding: 0 5px;

}

.code-btn {
  height: 31px;
  margin-left: 30px;
}

.submit-btn {

  letter-spacing: 2px;
  background: #5a84fd;
  width: 45%;
  height: 35px;
  margin-left: 80px;
}

.des {
  padding-top: 25px;
  font-size: 13px;
  text-align: center;
  color: #91949c;
  letter-spacing: 2px;
}

.main {
  width: 300px;
  height: 300px;
  position: relative;
  left: 5%;
  top: 0%;
}
</style>