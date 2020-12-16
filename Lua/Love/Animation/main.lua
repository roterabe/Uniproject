local fps = 7

local frame = 1

local animation_duration = 1 / fps

local frame_number = 3

local xupdate

function love.load()
    font = love.graphics.newFont(14)
    love.graphics.setFont(font)
    walkinganim = love.graphics.newImage("ex.png")
    walk = love.graphics.newQuad(0, 0, 250, 300, walkinganim:getWidth(), walkinganim:getHeight())
    love.graphics.setBackgroundColor(255, 255, 255)
end

function love.update(dt)
    if dt < 0.04 then

        animation_duration = animation_duration - dt

        if animation_duration <= 0 then

            animation_duration = 1 / fps

            frame = frame + 1

            if frame > frame_number then

                frame = 1

            end
            xupdate = 230 * (frame - 1)
            if frame == 3 then
                xupdate = xupdate + 100
                walk:setViewport(xupdate, 0, 320, 300)
            elseif frame == 2 then
                walk:setViewport(xupdate, 0, 320, 300)
            else
                walk:setViewport(xupdate, 0, 250, 300)
            end
        end

    else

        return

    end

end

function love.draw()
    love.graphics.draw(walkinganim, walk, 100, 200, 0, 0.3, 0.3)
end
