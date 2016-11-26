# Контроллер для плавного включения света по датчикам движения
Описание проекта: в этом проекте я бы хотел поделиться с вами тем, как сделать контроллер с датчиками движения. Если вы устали все время нажимать на выключатели, чтобы включить или выключить свет, или не хотите чтобы лампа горела в корридоре всю ночь, а также вы имеет хотя бы основные умения в программировании и работе с "железом", тогда эта статья для вас! В этом описание я хотел бы помочь вам облегчить вашу жизнь. Итак это одна из простейших моделей контроллера, которую может собрать любой желающий. Основная реализация сделана в виде алгоритма. При срабатывании любого из датчиков движения вызывается прерывание (INT 0 или INT 1). Прерывание устанавливает глобальную переменную времени в течении которого свет включен. Обработка включения и выключения света производиться в основном цикле. Свет включается плавно по логарифмическому закону. Из-за этого мы видим изменение света как линейное. Схему "железа" можно увидеть на приложенной иллюстрации. В связи тем, что в библиотеке программы не было датчика движения, он был заменен обычной кнопкой.
Схему можно посмотреть в вики проекта.
