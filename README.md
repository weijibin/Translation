# Translation

## Veneno.ros.md

### language: java
jdk:
- oraclejdk8
sudo: required
dist: trusty
install: ./installViaTravis.sh
script: ./buildViaTravis.sh
cache:
  directories:
  - $HOME/.gradle/caches
env:
  global:
  - secure: WCRqvIKdPdIsoDhsJWZNBZhEH7Jdgz2fmkjzozVjs4dq36ySrH71udNtZcPIsTwjmHpRaGX0XCgmwLC5WorS2TBJJ87oghCP3WWQGMBLcCdXHS8quRdAHLHpNfao/BQrBEA/gmCYoJZdmXKFDc+XKXS5NBrHkkvVfLGCumcP0AI=
  - secure: TKnGiZyCtWWI/ei2lNDvGIjyAI4W8xMNOlXT6tGiWJgexvFQpTl2NgkMqgwbxReyxj37vdUnn9Lb/883G6zL/uB+l5aCjeCG//6GAbJYdrSZQCE/UCo7iMlAxyqfuIlKcJABIhwpP8Fg4RwqxJG19Tbx5ddg8RP8yKAi1QNx06Y=
  - secure: nUn8s+1fV60Hxb9V9DouFIOGHeBpeTD7l6Yadw4gthvi/tZndZ+L/Crh1Z9pAU69NqEHG/VcFLUMNER7dQ4rugVbcbfQueeCdnVpmStLS97tAl8kArhpWCk8dQi47IANuQw7U0nVlg3pA8w9HLZX6ee9PnhyG1oOnluPC/x2Or4=
  - secure: KTtxnPJWfkwNwYkd2IxKAc4dUc6jF0Fd6uhrqK5q36z0RnY4b/gKlx8bjGPcZA5hutNmiN/gxyvpbL/bvVg9buQ2vkybaPZpzpLwhHTXiD5accjQUMuwF8DFYpzIb104hkgzHbrW18JRImK539ib5TTanF3I08F04LssSXG8NnY=
