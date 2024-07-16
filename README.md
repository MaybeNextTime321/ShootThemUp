# ShootThemUp

Проект на Unreal Engine 4 по курсу [Udemy](https://www.udemy.com/course/unrealengine/).

Этот проект создан мной в рамках курса на Udemy, где я учусь программировать на C++ под Unreal Engine 4. Основной целью курса было создание шутера от третьего лица под названием ShootThemUp.

### Особенности проекта

- **Основы C++ и архитектура Unreal Engine:** Изучил основные классы, типы, макросы и делегаты.
- **Создание и управление анимациями:** Реализовал стейт машину, FABRIK, и anim notifies.
- **Система здоровья:** Включает получение урона, смерть, автохил и урон от падения с высоты.
- **Функционал оружия:** Два типа оружия, стрельба по таймеру, боеприпасы, перезарядка и урон ракетами.
- **Искусственный интеллект:** Противники ищут и стреляют по персонажу, подбирают пикапы и перезаряжаются.
- **Пользовательские интерфейсы (UMG):** Создание HUD, шкалы здоровья и данных о боеприпасах.
- **Визуальные эффекты (Niagara):** Реализованы эффекты выстрела, следы от пуль и визуальные эффекты попадания.
- **Управление звуком:** Настроены SoundCue, SoundClass, SoundMix и Attenuation settings.
- **Контролирование процесса игры:** Настроены GameMode, PlayerState и GameInstance.
- **Динамическая подгрузка уровней:** Реализовано для более плавного игрового процесса.

## Текущий статус задач

| Задача | Статус |
| ------ | ------ |
| Анимации движения, камера | ✅ Работает |
| Здоровье персонажа, получение урона, смерть, автохил, урон от падения с высоты | ✅ Работает |
| Оружие: два типа, стрельба по таймеру, боеприпасы, перезарядка, урон ракетами | ✅ Работа восстановлена |
| Шкала здоровья персонажа, данные о боекомплекте, прицел | ✅ Работа восстановлена |
| Пикапы здоровья и патронов | ✅ Написано, работает |
| Эффект выстрела, следы от пуль, визуальные эффекты попадания и выстрела | ✅ Работает |
| Искусственный интеллект противников: поиск и стрельба, подбор пикапов, перезарядка | ✅ Работа восстановлена |
| Настройка гейммода, распределение по командам, подсчет статистики | ✅ Написано, работает |
| Интерфейс игры: переход между режимами, перезагрузка уровней, пауза игры | ✅ Написано, работает |
| Звуки ходьбы, бега, прыжков, смерти, отсутствия боеприпасов | ⏳ Будет написано |

## Установка и запуск проекта

Пошаговая инструкция по клонированию и запуску проекта.

```bash
# Клонируем репозиторий
https://github.com/MaybeNextTime321/ShootThemUp.git

# Переходим в директорию проекта
cd ShootThemUp

# Открываем проект в Unreal Engine 4
# Для этого просто дважды щелкните на .uproject файл в корневой директории проекта
