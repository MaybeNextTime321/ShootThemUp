# ShootThemUp

## Languages
- English
- Русский

<a name="english"></a>
## English

ShootThemUp is a project developed using Unreal Engine 4 as part of a Udemy course. The game is a third-person shooter where players battle in teams or against each other, utilizing various types of weapons and tactical skills. The project involves learning C++ basics and Unreal Engine architecture, creating animations, setting up health systems, managing weapons, implementing artificial intelligence and visual effects, as well as developing user interfaces and sound design.

- **Movement System**
- **Health Component**
- **Weapons**
- **Interface**
- **Pickups**
- **Visual Effects**
- **Artificial Intelligence**
- **Game Mode**
- **Sounds**

### Movement System
The project features core character movement mechanics, including walking, running, and jumping, as well as camera control to enhance gameplay. An animation blueprint was developed to ensure smooth transitions between animations, maintaining consistency and high quality of character movements.


### Health Component
The health component manages damage and healing processes for the character. It includes handling damage from weapons, auto-healing, and fall damage. These features add realism to the game and contribute to a more engaging gameplay experience.

### Weapons
The project features two types of weapons: a rifle and a grenade launcher. Each weapon has unique characteristics and functionalities.

1. **Rifle:**
   - **Functionality:** The primary weapon that allows players to fire in bursts. It is effective at medium range and suitable for most combat situations.
   - **Timed Shooting:** The rifle uses a timer system to regulate the intervals between shots, ensuring a consistent firing rate.
   - **Ammunition:** Includes a system for managing ammunition and reloading. Players need to monitor their ammo count and reload as needed.

2. **Grenade Launcher:**
   - **Functionality:** An advanced weapon that fires grenades. The grenade launcher is effective against groups of enemies and can deal damage within the explosion radius.
   - **Timed Shooting:** The grenade launcher is equipped with a timer to control shooting intervals, allowing for controlled attack rates.
   - **Ammunition:** Includes an ammunition management system for grenades, with replenishment and reloading capabilities.


### Interface
The project includes several user interfaces (UI) that provide players with essential information and enhance the overall gaming experience.

1. **HUD (Head-Up Display):**
   - **Elements:** The main HUD displays critical information about the player's status, including current ammo count, health, and active weapon status.
   - **Functionality:** Features health indicators, ammo count, and counters that update in real-time based on player actions.

2. **Health Bar:**
   - **Elements:** An intuitive health bar showing the current health status of the character.
   - **Functionality:** Updates in real-time in response to damage taken or health regeneration. Allows players to quickly assess the character’s current health state.

3. **Ammunition Data:**
   - **Elements:** Information about the number of rounds for the current weapon.
   - **Functionality:** Displays the current ammo count and spare ammunition, updating based on firing and reloading actions.

4. **Pause and Settings Menu:**
   - **Elements:** Menu for pausing the game, adjusting settings, and accessing additional options.
   - **Functionality:** Allows players to pause the game, modify control and graphics settings, and return to the main menu.

5. **Final Scoreboard:**
   - **Elements:** A table displaying the results at the end of the match.
   - **Functionality:** Shows the number of kills and deaths for each player on the map.

### Pickups
The project features health and ammunition pickups that enhance gameplay by providing players with additional resources. These pickups have a static appearance and disappear for a period after being collected, before becoming available again.

1. **Health Pickups:**
   - **Functionality:** Restore the player's health upon interaction. Health pickups have a static appearance and are placed in visible locations on the levels.
   - **Behavior:** After being collected, the pickup disappears for a certain period (e.g., 30 seconds) and then becomes available again. This approach balances the availability of resources and maintains player engagement.

2. **Ammunition Pickups:**
   - **Functionality:** Provide additional ammunition for the current weapon. Ammunition pickups also have a static appearance and are positioned in accessible spots on the levels.
   - **Behavior:** Once collected, the pickup disappears for a set amount of time (e.g., 30 seconds) and then reappears. This ensures a steady supply of ammunition while keeping the gameplay balanced.

Both types of pickups are designed with visual and sound effects for better perception and to enhance the gaming experience. They are integrated into the levels to provide strategic opportunities and improve the overall dynamics of the game.

### Visual Effects
The project features various visual effects that enhance the perception and atmosphere of the game. We have configured flash effects for gunshots and impacts for each type of weapon, as well as realistic impact decals.

1. **Flash Effects for Shots and Impacts:**
   - **Functionality:** Separate flash effects have been set up for each weapon, displayed during shooting and impact.

2. **Surface Detection and Effect Variation:**
   - **Functionality:** For the rifle, we have implemented surface detection to determine the type of surface hit by a bullet. Depending on the material, the visual impact effect changes accordingly. 

3. **Impact Decals:**
   - **Functionality:** When a bullet hits a surface, decals are left behind. These decals highlight the interaction between the bullet and the environment, adding detail and realism to the gameplay.

### Artificial Intelligence

The artificial intelligence (AI) in the project provides enemies with dynamic behavior, creating a more engaging and challenging gameplay experience. Bots have the following capabilities:

1. **Enemy Search:**
   - **Functionality:** Bots can navigate the map and actively search for enemy team members.

2. **Attacking:**
   - **Functionality:** When a bot detects an enemy player, it starts attacking them. Bots are capable of aiming and shooting, using their current weapons and ammunition.

3. **Ammunition Management:**
   - **Functionality:** If a bot runs out of ammunition, it automatically switches weapons. This ensures continuous attack and allows bots to remain effective in combat.

4. **Resource Pickup:**
   - **Functionality:** When low on health or ammunition, bots will seek out and pick up pickups scattered around the map. This helps them maintain their combat effectiveness and stay active in the gameplay.

### Game Mode
The game mode includes key features for managing the gameplay and configuring game settings, enabling diverse scenarios and more effective game management.

1. **Team Division:**
   - **Functionality:** Players and bots are divided into teams, allowing for team-based battles and setting rules for player interactions.

2. **Round Time and Count Settings:**
   - **Functionality:** The game mode provides settings for defining the duration of each round and the total number of rounds in the game. This allows for flexible adjustment of game length and structure based on preferences.

3. **Character Respawn at the Start of Each Round:**
   - **Functionality:** At the beginning of each round, all characters respawn. This ensures equal conditions for all players and resets the game state, starting each round from a fresh state.

### Sounds
## Sounds

The project features a variety of sound effects that add depth and atmosphere to the gameplay. The following sounds are implemented:

1. **Interface Sounds:**
2. **Ambient Sounds:**
3. **Pickup Sounds:**
4. **Footsteps, Jumping, and Landing Sounds:**
5. **Gunshot Sounds:**
6. **Impact Sounds on Materials and Body Parts:**

These sounds are integrated to create a complete and immersive audio-visual atmosphere, enhancing the overall player experience.
________________________________________________________________________________________________________________________

## Русский

ShootThemUp — это проект на Unreal Engine 4, разработанный в рамках курса на Udemy. Игра представляет собой шутер от третьего лица, где игроки сражаются в команде или против друг друга, используя различные виды оружия и тактические навыки. Проект включает в себя изучение основ C++ и архитектуры Unreal Engine, создание анимаций, настройку системы здоровья, управление оружием, реализацию искусственного интеллекта и визуальных эффектов, а также разработку пользовательских интерфейсов и звукового оформления.

- **Система передвижения**
- **Компонент здоровья** 
- **Оружие** 
- **Интерфейс**
- **Пикапы**
- **Визуальные эффекты**
- **Искусственный интеллект**
- **Гейммод**
- **Звуки**
  
### Система передвижения
В проекте реализованы основные механики передвижения персонажа, включая ходьбу, бег и прыжки. Также настроено управление камерой для улучшения игрового процесса. Для обеспечения плавных переходов между анимациями создан анимационный блюпринт, который отвечает за согласованность движений и качественные анимации персонажа.


### Компонент здоровья
Компонент здоровья в проекте управляет процессами получения урона и лечения персонажа. Он включает в себя обработку урона от оружия, автоматическое восстановление здоровья и урон от падения с высоты. Эти функции добавляют реалистичности в игру и способствуют более увлекательному игровому процессу.

### Оружие
В проекте реализованы два типа оружия: винтовка и гранатомет. Каждый вид оружия обладает уникальными характеристиками и функциональностью.

1. **Винтовка:**
   - **Функциональность:** Основное оружие, которое позволяет игроку стрелять очередями из винтовки. Она эффективна на средней дистанции и подходит для большинства боевых ситуаций.
   - **Стрельба по таймеру:** Винтовка использует систему таймера для регулирования интервалов между выстрелами, что обеспечивает стабильный темп стрельбы.
   - **Боеприпасы:** Управление запасом патронов и процесс перезарядки включены в систему. Игрокам нужно следить за количеством патронов и своевременно производить перезарядку.

2. **Гранатомет:**
   - **Функциональность:** Продвинутое оружие, которое позволяет стрелять гранатами. Гранатомет эффективен против групп врагов и может наносить урон в зоне взрыва.
   - **Стрельба по таймеру:** Гранатомет оснащён таймером для контроля интервалов между выстрелами, что позволяет управлять темпом атаки.
   - **Боеприпасы:** Система управления боеприпасами для гранат, с возможностью пополнения и перезарядки.
  
     
### Интерфейс
В проекте реализованы несколько пользовательских интерфейсов (UI), которые обеспечивают удобное взаимодействие игрока с игрой и представляют ключевую информацию.

1. **HUD (Head-Up Display):**
   - **Элементы:** Основной HUD отображает важную информацию о состоянии персонажа, включая текущие запасы боеприпасов, здоровье и статус активного оружия.
   - **Функциональность:** Включает в себя индикаторы здоровья, количества патронов и счетчики, которые обновляются в реальном времени в зависимости от действий игрока.

2. **Шкала здоровья:**
   - **Элементы:** Интуитивно понятная шкала здоровья, отображающая текущее состояние здоровья персонажа.
   - **Функциональность:** Обновляется в реальном времени в ответ на получение урона или восстановление здоровья. Используется для быстрого понимания текущего состояния персонажа.

3. **Данные о боеприпасах:**
   - **Элементы:** Информация о количестве боеприпасов для текущего оружия.
   - **Функциональность:** Отображает текущее количество патронов в оружии и запасные патроны, обновляясь в зависимости от стрельбы и перезарядки.

4. **Меню паузы и настроек:**
   - **Элементы:** Меню для приостановки игры, изменения настроек и доступа к дополнительным опциям.
   - **Функциональность:** Позволяет игрокам приостанавливать игру, изменять настройки управления и графики, а также выходить в главное меню.

5. **Финальная таблица:**
   - **Элементы:** Таблица, отображающая результаты игры в конце матча.
   - **Функциональность:** Показывает количество убийств и смертей каждого игрока на карте.

### Пикапы
В проекте реализованы пикапы здоровья и боеприпасов, которые добавляют динамику в игровой процесс и предоставляют игрокам дополнительные возможности. Эти пикапы имеют статичный вид и исчезают на некоторое время после подбора, после чего снова становятся доступными для сбора.

1. **Пикапы здоровья:**
   - **Функциональность:** Восстанавливают здоровье игрока при взаимодействии. Пикапы здоровья имеют статичный внешний вид и размещаются на уровнях в видимых местах.
   - **Поведение:** После подбора пикап исчезает на некоторое время (например, 30 секунд) и затем снова становится доступным для сбора. Это позволяет сбалансировать доступность ресурсов и поддерживать интерес игроков.

2. **Пикапы боеприпасов:**
   - **Функциональность:** Обеспечивают дополнительными боеприпасами для текущего оружия. Пикапы боеприпасов также имеют статичный вид и расположены на уровнях в удобных местах для нахождения игроками.
   - **Поведение:** После того как игрок подбирает боеприпасы, пикап исчезает на установленное время (например, 30 секунд) и затем возобновляется. Это позволяет игрокам регулярно находить боеприпасы, поддерживая сбалансированный игровой процесс.

Оба типа пикапов проектируются с визуальными и звуковыми эффектами для лучшего восприятия и добавления игрового опыта. Они интегрированы в уровни таким образом, чтобы предоставить игрокам стратегические возможности и улучшить общую динамику игры.

### Визуальные эффекты
В проекте реализованы различные визуальные эффекты, которые улучшают восприятие и атмосферу игры. Мы настроили эффекты вспышек от выстрелов и попаданий для каждого типа оружия, а также добавили реалистичные следы от попаданий.

1. **Вспышки от выстрелов и попаданий:**
   - **Функциональность:** Для каждого оружия настроены отдельные эффекты вспышек, которые отображаются при стрельбе и попадении

2. **Определение поверхности и изменение эффектов:**
   - **Функциональность:** Для винтовки реализовано определение типа поверхности, по которой попадает пуля. В зависимости от материала, визуальный эффект попадания изменяется. 

3. **Следы от попаданий (Decals):**
   - **Функциональность:** При попадании пули в поверхность остаются следы в виде декалей. Эти следы помогают подчеркнуть взаимодействие пули с окружающим миром.



### Искусственный интеллект
Искусственный интеллект (ИИ) в проекте предоставляет врагам динамичное поведение, создавая более увлекательный и сложный игровой процесс. Боты обладают следующими функциями:

1. **Поиск врагов:**
   - **Функциональность:** Боты могут перемещаться по карте и активно искать членов вражеской команды. 

2. **Атака:**
   - **Функциональность:** Когда бот обнаруживает вражеского игрока, он начинает атаковать его. Боты умеют прицеливаться и стрелять, используя свои текущие оружие и боеприпасы.

3. **Управление боеприпасами:**
   - **Функциональность:** Если у бота заканчиваются боеприпасы, он автоматически меняет оружие. Это обеспечивает непрерывность атаки и позволяет ботам оставаться эффективными в бою.

4. **Подбор ресурсов:**
   - **Функциональность:** В случае нехватки здоровья или боеприпасов, бот будет искать и подбирать пикапы, расположенные на карте. Это позволяет им поддерживать свою боеспособность и активно участвовать в игровом процессе.


### Гейммод
В гейммоде реализованы ключевые функции для управления игровым процессом и настройки параметров игры, что позволяет создать разнообразные сценарии и управлять игрой более эффективно.

1. **Разделение персонажей на команды:**
   - **Функциональность:** Игроки и боты делятся на команды, что позволяет организовать командные сражения и установить правила взаимодействия между игроками.

2. **Настройка времени и количества раундов:**
   - **Функциональность:** В гейммоде предусмотрены настройки для определения времени продолжительности каждого раунда и общего количества раундов в игре. Это позволяет гибко настраивать продолжительность и структуру игры в зависимости от предпочтений.

3. **Перезапуск персонажей в начале каждого раунда:**
   - **Функциональность:** В начале каждого раунда все персонажи спавнятся заново. Это обеспечивает равные условия для всех игроков и позволяет сбросить состояние игры, начиная каждый раунд с чистого листа.


### Звуки
В проекте реализована разнообразная звуковая поддержка, которая добавляет глубину и атмосферу в игровой процесс. Настроены следующие звуки:

1. **Звуки интерфейса:**
2. **Фоновые звуки:**
3. **Звуки подбора пикапов:**
4. **Звуки шагов, прыжков и приземления:**
5. **Звуки выстрелов:**
6. **Звуки попадания по материалам и частям тела:**

Эти звуки интегрированы для создания полной и увлекательной аудиовизуальной атмосферы, улучшая общий опыт игрока.
