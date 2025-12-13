# 408考研

距离政治考研还有 <span id="countdown1">
  <span id="days1">0</span> 天
  <span id="hours1">0</span> 时
  <span id="minutes1">0</span> 分
  <span id="seconds1">0</span> 秒
</span>

距离英语考研还有 <span id="countdown2">
  <span id="days2">0</span> 天
  <span id="hours2">0</span> 时
  <span id="minutes2">0</span> 分
  <span id="seconds2">0</span> 秒
</span>

距离数学考研还有 <span id="countdown3">
  <span id="days3">0</span> 天
  <span id="hours3">0</span> 时
  <span id="minutes3">0</span> 分
  <span id="seconds3">0</span> 秒
</span>

距离 408 考研还有 <span id="countdown4">
  <span id="days4">0</span> 天
  <span id="hours4">0</span> 时
  <span id="minutes4">0</span> 分
  <span id="seconds4">0</span> 秒
</span>




<script>
  // 通用倒计时函数
  function createCountdown(targetDateString, countdownId) {
    const targetTime = new Date(targetDateString).getTime();
    let timer;

    function updateCountdown() {
      const now = Date.now();
      let diff = targetTime - now;

      if (diff <= 0) {
        document.getElementById(countdownId).innerText = "倒计时结束";
        clearInterval(timer);
        return;
      }

      const seconds = Math.floor(diff / 1000) % 60;
      const minutes = Math.floor(diff / (1000 * 60)) % 60;
      const hours   = Math.floor(diff / (1000 * 60 * 60)) % 24;
      const days    = Math.floor(diff / (1000 * 60 * 60 * 24));

      document.getElementById(`days${countdownId.slice(-1)}`).innerText = days;
      document.getElementById(`hours${countdownId.slice(-1)}`).innerText = hours;
      document.getElementById(`minutes${countdownId.slice(-1)}`).innerText = minutes;
      document.getElementById(`seconds${countdownId.slice(-1)}`).innerText = seconds;
    }

    updateCountdown();
    timer = setInterval(updateCountdown, 1000);
  }

  createCountdown("2027-12-25T08:30:00+08:00", "countdown1");
  createCountdown("2027-12-25T14:00:00+08:00", "countdown2");
  createCountdown("2027-12-26T08:30:00+08:00", "countdown3");
  createCountdown("2027-12-26T14:00:00+08:00", "countdown4");
</script>