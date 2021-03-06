﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Robocode;
using System.Drawing;

namespace MF_Robots
{
    class FirstBot_debug : Robot
    {
        // The coordinates of the last scanned robot
        private int scannedX = int.MinValue;
        private int scannedY = int.MinValue;

        // The main method of your robot containing robot logics
        public override void Run()
        {
            // -- Initialization of the robot --

            SetColors(System.Drawing.Color.Black, System.Drawing.Color.Black, System.Drawing.Color.Black);

            // Here we turn the robot to point upwards, and move the gun 90 degrees
            TurnLeft(Heading - 90);
            TurnGunRight(90);

            // Infinite loop making sure this robot runs till the end of the battle round
            while (true)
            {
                // -- Commands that are repeated forever --

                // Move our robot 5000 pixels ahead
                Ahead(5000);

                // Turn the robot 90 degrees
                TurnRight(90);

                // Our robot will move along the borders of the battle field
                // by repeating the above two statements.
            }
        }

        // Robot event handler, when the robot sees another robot
        public override void OnScannedRobot(ScannedRobotEvent e)
        {
            Console.WriteLine("Enemy spotted, I'm at: " + X.ToString() + ", " + Y.ToString());
            // demonstrate feature of debugging properties on RobotDialog
            DebugProperty["lastScannedRobot"] = e.Name + " at " + e.Bearing + " degrees, " + e.Distance + " pixels away, at time " + Time;

            // Calculate the angle to the scanned robot
            double angle = Math.PI * ((this.Heading + e.Bearing) % 360) / 180.0;

            // Calculate the coordinates of the robot
            scannedX = (int)(this.X + Math.Sin(angle) * e.Distance);
            scannedY = (int)(this.Y + Math.Cos(angle) * e.Distance);

            // Assuming radar and gun are aligned... 
            if (e.Distance < 100)
            {
                Fire(3);
            }
            else
            {
                Fire(0.5);
            }
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
