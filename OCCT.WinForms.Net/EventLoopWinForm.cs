using System;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModelCAD.WinForms.Net
{
	public class EventLoopWinForm : EventLoop
	{
		private Timer mTimer = new Timer();

		public override uint OnRun() {
			mTimer.Tick += TimerEventProcessor;
			mTimer.Interval = 500;
			mTimer.Start();
			while(!GetExit()) {
				Application.DoEvents();
			}
			return GetCode();
		}

		public override void OnGetIntegerValue(string name, int val) {
			if(InputManager.GetInteger != null) {
				InputManager.GetInteger(name, val);
			}
		}

		public override void OnGetDoubleValue(string name, double val) {
			if(InputManager.GetDouble != null) {
				InputManager.GetDouble(name, val);
			}
		}

		private void TimerEventProcessor(object sender, EventArgs e) {
			mTimer.Stop();
			if(!GetExit()) {
				mTimer.Enabled = true;
			}
		}
	}
}
