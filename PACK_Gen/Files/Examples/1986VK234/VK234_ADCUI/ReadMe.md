# Примеры работы с блоком электросчетчика в 1986ВК234

На текущий момент пример содержит только инициализацию блока тремя разными способами:
  * Напрямую в регистры блока. Названия полей регистров соответствуют спецификации.
  * Через структуру RegCfg, в которую вынесены только регистры содержащие настройки. Поля регистров названы более читабельно.
  * Через структуру Cfg, в которой настройки сгруппированы согласно назначению. Удобно для восприятия доступных опций.

Проект управляется кнопками:
  * Key1 - переключение  вариантов настройки блока (разными способами). Настроки сейчас мало отличаются, можно поменять по своему усмотрению.
  * Key2 - переключение выводимого результата на LCD панель.
  * Key3 - Ручной запуск вывода на экран - если системный таймер не используется.
  * Key4 - Смена канала, который выводится на экран - F0, F1, F2.

Обновление экрана происходит по системному таймеру. Отображение на экране:
  * ABC : над цифрами - текущий канал F0, F1, F2
  * A : канал тока I
  * V : канал напряжения V0
  * A круг : канал тока I3
  * А Сумма: RMS_I
  * V Сумма: RMS_V
  * A : Активная мощность
  * R : Реактивная мощность
  * Сумма : Полная мощность
  * Время A+ : Положительная активная энергия
  * Время A- : Отрицательная активная энергия
  * Время R+ : Положительная реактивная энергия
  * Время R- : Отрицательная реактивная энергия  
  * Время Сумма : Полная энергия