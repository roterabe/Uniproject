#!/usr/bin/env python3

import wx


class BMICalculator(wx.Frame):
    def __init__(self, parent, id):

        # Set panel to not resize and with static labels.
        no_resize = wx.DEFAULT_FRAME_STYLE & ~ (wx.RESIZE_BORDER |
                                                wx.MAXIMIZE_BOX)
        super().__init__(
            None, title="BMI Calculator",
            size=(430, 280), style=no_resize)
        self.panel = wx.Panel(self)
        self.Show()
        self.panel.SetBackgroundColour("#FFFFFF")
        self.Centre()

        # Set static labels.
        self.info_text = wx.StaticText(
            self.panel, -1, "Enter your height and weight in cm and kg in order to receive your BMI:", (20, 15))
        self.resultLabel = wx.StaticText(self.panel, -1, "BMI: ", (20, 50))
        self.heightLabel = wx.StaticText(self.panel, -1, "Height:", (20, 90))
        self.heightUnit = wx.StaticText(self.panel, -1, ".cm", (130, 90))
        self.weightLabel = wx.StaticText(self.panel, -1, "Weight:", (20, 130))
        self.weightUnit = wx.StaticText(self.panel, -1, ".kg", (130, 130))
        self.underweightLabel = wx.StaticText(self.panel, -1, "Underweight = < 18.5", (253, 90))
        self.normalLabel = wx.StaticText(self.panel, -1, "Normal weight = 18.5-24.9", (239, 110))
        self.overweightLabel = wx.StaticText(self.panel, -1, "Overweight = 25-29.9", (254, 130))
        self.obeseLabel = wx.StaticText(self.panel, -1, "Obesity = > 30", (274, 150))

        # Set buttons.
        self.Calculate = wx.Button(self.panel, label="Result", pos=(40, 170), size=(60, -1))
        self.Reset = wx.Button(self.panel, label="Reset", pos=(122, 170), size=(60, -1))
        self.result = wx.StaticText(self.panel, -1, "0", (50, 50))
        self.Calculate.SetBackgroundColour("White")
        self.Calculate.Bind(wx.EVT_BUTTON, self.Calc)

        self.Reset.SetBackgroundColour("White")
        self.Reset.Bind(wx.EVT_BUTTON, self.Res)

        # self.error_text = wx.StaticText(self.panel, -1, "", (269, 65))
        # Set input field.
        self.height = wx.SpinCtrlDouble(self.panel, -1, pos=(65, 87), size=(60, -1), min=0, max=300)
        self.weight = wx.SpinCtrlDouble(self.panel, -1, pos=(65, 127), size=(60, -1), min=0, max=300)

    def Calc(self, event):
        if (self.calcBMI(self.height.GetValue(), self.weight.GetValue()) is None):
            self.result.SetLabel("Error: Height or weight cannot be 0!")
        else:
            self.result.SetLabel(str(self.calcBMI(
                self.height.GetValue(), self.weight.GetValue())))

    def Res(self, event):
        self.result.SetLabel("0")
        self.height.SetValue(0)
        self.weight.SetValue(0)

    def calcBMI(self, height, weight):
        # self.error_text.SetLabel("")
        h = float(height) / 100
        if (h**2 == 0 or weight == 0):
            return None
        BMI = weight / h**2
        return BMI


app = wx.App()
frame = BMICalculator(None, -1)
frame.Show()
app.MainLoop()
