using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Robocode;
using System.Drawing;

// based on:
// http://www.ibm.com/developerworks/java/library/j-dodge/

namespace MF_Robots
{
    class FirstBot_dodge : AdvancedRobot
    {
        // The coordinates of the last scanned robot
        private int scannedX = int.MinValue;
        private int scannedY = int.MinValue;

        // properties used for dodging
        private double previousEnergy = 100;
        private int movementDirection = 1;
        private int gunDirection = 1;

        // The main method of your robot containing robot logics
        public override void Run()
        {
            // -- Initialization of the robot --

            SetColors(Color.Black, Color.Black, Color.Black);

            SetTurnGunRight(99999);
        }

        // Robot event handler, when the robot sees another robot
        public override void OnScannedRobot(ScannedRobotEvent e)
        {
            Console.WriteLine("Enemy spotted!");
            // demonstrate feature of debugging properties on RobotDialog
            DebugProperty["lastScannedRobot"] = e.Name + " at " + e.Bearing + " degrees at time " + Time;

            // Calculate the angle to the scanned robot
            double angle = Math.PI * ((this.Heading + e.Bearing) % 360) / 180.0;

            // Calculate the coordinates of the robot
            scannedX = (int)(this.X + Math.Sin(angle) * e.Distance);
            scannedY = (int)(this.Y + Math.Cos(angle) * e.Distance);

            // Stay at right angles to the opponent
            SetTurnRight(e.Bearing + 90 - 30 * movementDirection);
         
            // If the bot has small energy drop, assume it fired
            double changeInEnergy = previousEnergy - e.Energy;
            if (changeInEnergy > 0 && changeInEnergy <= 3)
            {
                // Dodge!
                movementDirection = -movementDirection;
                SetAhead((e.Distance / 4 + 25) * movementDirection);
            }
            // When a bot is spotted, sweep the gun and radar
            gunDirection = -gunDirection;
            SetTurnGunRight(99999*gunDirection);
    
            // Track the energy level
            previousEnergy = e.Energy;
        }

        // Paint a transparent square on top of the last scanned robot
        public override void OnPaint(IGraphics graphics)
        {
            // Set the paint color to a red half transparent color
            //graphics.SetColor(new Color(0xff, 0x00, 0x00, 0x80));
            Pen newPen = new Pen(Color.Red);

            // Draw a line from our robot to the scanned robot
            graphics.DrawLine(newPen, scannedX, scannedY, (int)this.X, (int)this.Y);

            SolidBrush newBrush = new SolidBrush(Color.Blue);
            // Draw a filled square on top of the scanned robot that covers it
            graphics.FillRectangle(newBrush, new Rectangle(scannedX - 20, scannedY - 20, 40, 40));
        }
    }
}
