local library = loadstring(game:HttpGet("https://raw.githubusercontent.com/NiceBBMBThai12/NBTScript/main/UI-Library-Robloxx"))()
local window = library:Win()
local tap1 = window:addtap("HEE GIMEING")
local page1 = tap1:addpage()
page1:Ti("[+]")

page1:Toggle("Fast Attack",_G.FastAttk,function(value)
            _G.FastAttk = value
        end)
    
local CombatFrameworkR = require(game:GetService("Players").LocalPlayer.PlayerScripts.CombatFramework) 

local CameraShakerR = require(game.ReplicatedStorage.Util.CameraShaker)

spawn(function()
    for i = 1,math.huge do
        game:GetService("RunService").Heartbeat:wait()
        if _G.FastAttk then
            pcall(function()
                    CameraShakerR:Stop()
                    CombatFrameworkR.activeController.attacking = false
                    CombatFrameworkR.activeController.timeToNextAttack = 0
                    CombatFrameworkR.activeController.increment = 0.1
                    CombatFrameworkR.activeController.hitboxMagnitude = 35
            end)
        end
        game:GetService("RunService").Heartbeat:wait()
    end
end)

spawn(function()
    game:GetService("RunService").Heartbeat:connect(function()
        pcall(function()
            if _G.FastAttk then
                    VirtualUser:CaptureController()
                    VirtualUser:ClickButton1(Vector2.new(851, 158), game:GetService("Workspace").Camera.CFrame)
            end
        end)
    end)
    game:GetService("RunService").Heartbeat:connect(function()
        pcall(function()
            if _G.FastAttk then
                    VirtualUser:CaptureController()
                    VirtualUser:ClickButton1(Vector2.new(851, 158), game:GetService("Workspace").Camera.CFrame)
            end
        end)
    end)
end)

page1:Toggle("Bring Mob",function()
        function BringMob()
        for i,x in pairs(game:GetService("Workspace").Enemies:GetChildren()) do
            for n,y in pairs(game:GetService("Workspace").Enemies:GetChildren()) do
                if x.Name == Ms then
                    if y.Name == Ms then
                        x.HumanoidRootPart.CFrame = y.HumanoidRootPart.CFrame
                        x.HumanoidRootPart.CanCollide = false
                        y.HumanoidRootPart.CanCollide = false
                        y.Humanoid:ChangeState(11)
                        sethiddenproperty(game.Players.LocalPlayer, "SimulationRadius", math.huge)
                    end
                end
            end
        end
    end
    for i,v in pairs(game.Workspace.Enemies:GetChildren()) do
        if v.Name == Ms then
    v.HumanoidRootPart.Size = Vector3.new(60,60,60)
    v.HumanoidRootPart.Transparency = 1
        end
    end
end)
