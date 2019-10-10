-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 10, 2019 at 09:12 AM
-- Server version: 10.1.40-MariaDB
-- PHP Version: 7.3.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `elypsgm_nulled`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `ID` int(11) NOT NULL,
  `username` text NOT NULL,
  `password` varchar(129) NOT NULL,
  `score` int(11) NOT NULL DEFAULT '1',
  `money` int(11) NOT NULL,
  `email` varchar(85) NOT NULL,
  `faction` int(11) NOT NULL DEFAULT '0',
  `spawn_location` int(11) NOT NULL DEFAULT '1',
  `age` int(11) NOT NULL,
  `date_registred` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `skin` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `business`
--

CREATE TABLE `business` (
  `id` int(11) NOT NULL,
  `owned` int(11) NOT NULL DEFAULT '0',
  `type` int(11) NOT NULL,
  `MapIconID` int(11) NOT NULL,
  `PickupID` int(11) NOT NULL,
  `Price` int(11) NOT NULL,
  `bizzSafe` int(11) NOT NULL,
  `Owner` tinytext NOT NULL,
  `EnterFee` int(11) NOT NULL,
  `ExtCoords` tinytext NOT NULL,
  `IntCoords` tinytext NOT NULL,
  `VirtualWorld` int(11) NOT NULL,
  `Interior` int(11) NOT NULL,
  `name` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `business`
--

INSERT INTO `business` (`id`, `owned`, `type`, `MapIconID`, `PickupID`, `Price`, `bizzSafe`, `Owner`, `EnterFee`, `ExtCoords`, `IntCoords`, `VirtualWorld`, `Interior`, `name`) VALUES
(1, 0, 1, 55, 1581, 56000, 0, 'The State', 0, '1730.3346,-2369.1204,13.5469', '1730.3346,-2369.1204,13.5469', 0, 0, '{2a62d1}DMV\\n{ff6f21}/takedrivelicense {2a62d1}to get a\\ndriving license!');

-- --------------------------------------------------------

--
-- Table structure for table `map_icons`
--

CREATE TABLE `map_icons` (
  `id` int(11) NOT NULL,
  `type` int(11) NOT NULL,
  `position` tinytext NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `business`
--
ALTER TABLE `business`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `map_icons`
--
ALTER TABLE `map_icons`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `business`
--
ALTER TABLE `business`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `map_icons`
--
ALTER TABLE `map_icons`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
