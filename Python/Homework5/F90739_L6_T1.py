import wx
import time


class BMICalculator(wx.Frame):
    def __init__(self, parent, id):
        no_resize = wx.DEFAULT_FRAME_STYLE & ~ (wx.RESIZE_BORDER | 
                                                wx.MAXIMIZE_BOX)
        super().__init__(
            None, title="BMI Calculator",
            size=(350, 375), style=no_resize)
        self.panel = wx.Panel(self)
        self.Show()
        self.Size = (430, 280)
        # self.panel = wx.Panel(self)
        self.panel.SetBackgroundColour("#FFFFFF")
        self.Centre()
        self.info_text = wx.StaticText(
            self.panel, -1, "Enter your height and weight in cm and kg in order to receive your BMI:", (20, 15))
        self.label_text = wx.StaticText(self.panel, -1, "Body Mass Index: ", (20, 50))
        self.result_text = wx.StaticText(self.panel, -1, "... kg/(m*m)", (120, 50))
        self.error_label = wx.StaticText(self.panel, -1, "Error(s): ", (290, 50))
        self.error_text = wx.StaticText(self.panel, -1, "", (269, 65))
        self.static_text_height = wx.StaticText(self.panel, -1, "Height:", (20, 90))
        self.height = wx.SpinCtrlDouble(self.panel, -1, pos=(65, 87), size=(60, -1), min=0, max=300)
        # self.height1 = wx.Control(self.panel, -1, pos=(50, 70), size=(60, -1))
        self.static_text_height_extra = wx.StaticText(self.panel, -1, "(in centimeters)", (130, 90))
        self.static_text_weight = wx.StaticText(self.panel, -1, "Weight:", (20, 130))
        self.weight = wx.SpinCtrlDouble(self.panel, -1, pos=(65, 127), size=(60, -1), min=0, max=300)
        self.static_text_weight_extra = wx.StaticText(self.panel, -1, "(in kilograms)", (130, 130))
        self.bmi_underweight = wx.StaticText(self.panel, -1, "Underweight = < 18.5", (253, 90))
        self.bmi_normal_weight = wx.StaticText(self.panel, -1, "Normal weight = 18.5-24.9", (239, 110))
        self.bmi_overweight = wx.StaticText(self.panel, -1, "Overweight = 25-29.9", (254, 130))
        self.bmi_obesity = wx.StaticText(self.panel, -1, "Obesity = > 30", (274, 150))
        self.button_compute = wx.Button(self.panel, label="Result", pos=(40, 170), size=(60, -1))
        self.button_compute.SetBackgroundColour("White")
        self.button_compute.Bind(wx.EVT_BUTTON, self.Calc)
        self.button_refresh = wx.Button(self.panel, label="Reset", pos=(122, 170), size=(60, -1))
        self.button_refresh.SetBackgroundColour("White")
        self.button_refresh.Bind(wx.EVT_BUTTON, self.Reset)

    def Calc(self, event):
        if (self.compute_BMI(self.height.GetValue(), self.weight.GetValue()) is None):
            self.result_text.SetLabel("... kg/(m*m)")
        else:
            self.result_text.SetLabel(str(self.compute_BMI(
                self.height.GetValue(), self.weight.GetValue())) + " kg/(m*m)")
        self.button_compute.SetBackgroundColour((0, 0, 255))
        time.sleep(0.1)
        self.button_compute.SetBackgroundColour((0, 255, 0))

    def Reset(self, event):
        self.result_text.SetLabel("... kg/(m*m)")
        self.error_text.SetLabel("")
        self.height.SetValue(0)
        self.weight.SetValue(0)

    def onClose(self, event):
        self.Close(True)
        self.button_cancel.SetBackgroundColour((0, 0, 255))
        time.sleep(0.1)
        self.button_cancel.SetBackgroundColour((255, 0, 0))

    def errorZeroDivision(self):
        self.error_text.SetLabel("Division by zero")

    def compute_BMI(self, height, weight):
        self.error_text.SetLabel("")
        height_m = float(height) / 100
        if ((height_m * height_m) == 0):
            self.errorZeroDivision()
            return None
        BMI = weight / (height_m * height_m)
        return BMI


def main():
    app = wx.App()
    frame = BMICalculator(None, -1)
    frame.Show()
    app.MainLoop()


if __name__ == "__main__":
    main()
