local fps = 7

local frame = 1

local animation_dur = 1 / fps

local frame_number = 4

local xupdate

function love.load()
    font = love.graphics.newFont(14)
    love.graphics.setFont(font)
   --love.graphics.setColor(0, 0, 0, 255)
    character = {}
    character.x = 100
    character.y = 650
    character.w = 70
    character.h = character.w
    character.health = 120
    character.damage = 50
    character.alive = true

    enemy = {}
    enemy.x = 500
    enemy.y = 650
    enemy.w = 80
    enemy.h = enemy.w
    enemy.health = 120
    enemy.alive = true

    platform = {}
    platform.width = love.graphics.getWidth()
    platform.height = love.graphics.getHeight()

    platform.x = 0
    platform.y = platform.height / 1.2
    character.y = platform.y - character.h - 1
    enemy.y = platform.y - enemy.h - 1
    enemy.respawn = 0


    walkinganim = love.graphics.newImage("ex.png")
    walk = love.graphics.newQuad(0, 0, 200, 400, walkinganim:getWidth(), walkinganim:getHeight())

    --love.graphics.setColor(0, 0, 0, 225)
    love.graphics.setBackgroundColor(255, 153, 0)
end

function collision(x1, y1, w1, h1, x2, y2, w2, h2)
    return x1 < x2 + w2 and x2 < x1 + w1 and y1 < y2 + h2 and y2 < y1 + h1
end

--[[ function love.keypressed(key)
    dt = love.timer.getDelta()
    if key == 'k' then
        if collision(character.x, character.y, character.w, character.h, enemy.x, enemy.y, enemy.w, enemy.h) then
            if enemy.health <= 0 then
                enemy.alive = false
            end
            enemy.health = enemy.health - character.damage
        end
        character.w = character.w + 1 * dt * 2000
    end

end

function love.keyreleased(key)
    dt = love.timer.getDelta()
    if key == 'k' then
        character.w = character.w - 1 * dt * 2000
    end
end ]]

function love.update(dt)
    --[[ if dt < 0.04 then
        animation_dur = animation_dur - dt
        if animation_dur <= 0 then
            animation_dur = 1 / fps
            frame = frame + 1
            if frame > frame_number then
                frame = 1
            end
            xupdate = 12 * (frame - 1)
            walk:setViewport(xupdate, 0, 12, 12)
        else
            return
        end
    end
    if love.keyboard.isDown('d') then
        character.x = character.x + 1 * dt * 300
    elseif love.keyboard.isDown('a') then
        character.x = character.x - 1 * dt * 300
    elseif love.keyboard.isDown('k') then
        mem = character.w
        mem1 = character.w
        if collision(character.x, character.y, character.w, character.h, enemy.x, enemy.y, enemy.w, enemy.h) then
            if enemy.health <= 0 then
                enemy.alive = false
                enemy.respawn = 10
            end
            enemy.health = enemy.health - character.damage * dt
        end
    end
    if enemy.alive == false then
        if (enemy.respawn <= 0) then
            enemy.alive = true
            enemy.health = 120
        end
        enemy.respawn = enemy.respawn - dt
    end ]]
end

function love.draw()
    --[[ love.graphics.print(character.health, character.x, character.y - 20) ]]
    --love.graphics.rectangle("fill", platform.x, platform.y, platform.width, platform.height)
   --[[  if enemy.alive then
        love.graphics.print(enemy.health, enemy.x, enemy.y - 20)
        love.graphics.rectangle("fill", enemy.x, enemy.y, enemy.w, enemy.h)
    end ]]
    love.graphics.draw(walkinganim, walk, 100, 200, 0, 1, 1)
    --love.graphics.rectangle("fill", character.x, character.y, character.w, character.h)
end
