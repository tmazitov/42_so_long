# So Long

**So long** is a 2d game project from the 42 school curcus. This project provides to try to make own 2d game using Mini LibX ( see mlx folder ). This library contain basic functions for a interaction with the application window. As an example, you can draw an image using function **mlx_put_image**. It's important to say that Mini LibX not contain any support functions for the game development and if you want to make your game with amazing features you need to write all mechanics ( like colliders and etc. ) by yourself.

## Run (MAC only)
```bash
	./so_long ./maps/map1.ber
```
where **./maps/map1.ber** is path to the specific map

## How to play

* `WASD` - move ( one press is a one move, you can plan your move, max 3 future step)
* `SPACE` - attack ( have delay between activation )
* `SHIFT` - make action ( open chest or exit from the game on the exit place ) 

## My feature

1. Enemy features
	- **Move and attack** system with animations for each one side. Each one enemy action have a delay (1-2 seconds)
	- **Calculate the optimal path** to the player using A* algotrithm. When Player will stay in front of the enemy it will make a punch for him
	- **Health bar** like an image above the enemy with 3 healths
2. Player features
	- **Move and attack** system with animations for each one side
    - **Health bar** like an image above the enemy with 5 healths
3. Game objects
	- Chest with open and close animation. After the open at first time the player will get the coins
	- Money and Score legends at the top of the application window
	- The trees inside the border of the map are small
	- The bed like the exit place ( a reference to the tired me during the completion of the project )

## Your Own map

If you want to make your own map you need to create new file in **./maps** folder with **.ber** resolution. 
Any map contain:

|Object | Symbol | Desctiption|
|---------|------------|---------|
|Player init position|**P**|Where player character start the game on the map |
|Exit|**E**|The place of exit from the map|
|Free space|**0**|The space where the player or an enemies can move|
|Tree|**1**|Obstacles that cannot be passed through|
|Enemy|**S**|Init position of an enemy|
|Chest|**C**|Collectable chest with coins| 

Your map should to meet the conditions:
1) It must be rectangle
2) The map must have the border by the trees(**1**)
3) Only one init player position(**P**) and exit position(**E**)
4) Mininum one chest(**C**)
5) The player must have the way to the exit

If the map is wrong the programm will return the error with support message.

## Architecture

|Folder         |Description					|
|---------------|-------------------------------|
|cmd			|`Final programm files with configs`|
|game          	|`Main sources of the game like player, enemy or render`|
|maps          	|`Game maps`|
|mlx			|`Mini LibX`|
|textures		|`Images and animations for all game objects`|
|utils			|`Support functions and libraries`|
