﻿# Пример работы с блоком детектора питания.

В примере ищутся уровни питания выше и ниже текущего значения Ucc. 
А так-же количество программных (условных) циклов ожидания, за которое выставляется пороговый уровень. Это показывает, что выставление порогового уровня занимает некоторое время.

Результат выводится на экран LCD или на UART.

По кнопке UP (Key1) запускается тест для детектора Ucc. 
Типовой вывод на примере ВЕ1:
  Ucc  2.8  3.2       - диапазон в котором находится Ucc в вольтах
  Tr = 27,  Tf = 10   
    Tr - значение программного счетчика при переключении на пороговый уровень 3.2В, из текущего порога 2.8В.
    Tf - значение программного счетчика при переключении на пороговый уровень 2.8В, из текущего порога 3.2В.

По кнопке Right (Key2) запускается тест для детектора BUcc. Обычно тест выводит:
  Test Fault
  BUcc 3.0  3.0

Потому что BUcc подключено к Ucc, а Ucc всегда больше максимального порога для BUcc равного 3В.

## Проблемы в 1986ВК214
В 1986ВК214 добиться работоспособности блока не удалось. 
  * При записи значения 0xC2F в регистр PVDCS чтение показывает что значение в регистре оказалось 0xE2F. Т.е. включено прерывание по событию от Ucc, хотя этот бит не выставлялся.
  * Выставление бита PVDBEN приводит к тому, что постоянно генерируются прерывания как только их включаем в NVIC. При этом в прерывании видно, что в PVDCS нет ни флагов событий, ни разрешений каких-либо прерываний.
  * Перебор уровней по Ucc не приводит к выставлению флага PVD ни при каких условиях. Это видно по логу выводимому в UART.